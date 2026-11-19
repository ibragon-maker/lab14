#include "sorting.h"

bool score_descending(const ScoreEntry &a, const ScoreEntry &b) {
    return a.score > b.score;
}

bool name_ascending(const ScoreEntry &a, const ScoreEntry &b) {
    return a.name < b.name;
}


namespace {

/// Merge data[low..mid) and data[mid..high) into one sorted run, using
/// scratch as temporary space. Takes from the left run unless the right
/// element strictly belongs first, which keeps equal elements in order.
void merge_runs(ScoreEntry *data, ScoreEntry *scratch, int low, int mid,
                int high, Comparator before, long &comparisons) {
    int left = low;
    int right = mid;
    int out = low;
    while (left < mid && right < high) {
        ++comparisons;
        if (before(data[right], data[left])) {
            scratch[out++] = data[right++];
        } else {
            scratch[out++] = data[left++];
        }
    }
    while (left < mid) {
        scratch[out++] = data[left++];
    }
    while (right < high) {
        scratch[out++] = data[right++];
    }
    for (int i = low; i < high; ++i) {
        data[i] = scratch[i];
    }
}

void merge_sort_range(ScoreEntry *data, ScoreEntry *scratch, int low, int high,
                      Comparator before, long &comparisons) {
    if (high - low < 2) {
        return;
    }
    const int mid = low + (high - low) / 2;
    merge_sort_range(data, scratch, low, mid, before, comparisons);
    merge_sort_range(data, scratch, mid, high, before, comparisons);
    merge_runs(data, scratch, low, mid, high, before, comparisons);
}

} 

void merge_sort(ScoreEntry *data, int count, Comparator before,
                long &comparisons) {
    if (count < 2) {
        return;
    }
    ScoreEntry *scratch = new ScoreEntry[count];
    merge_sort_range(data, scratch, 0, count, before, comparisons);
    delete[] scratch;
}


/// Sort in place by repeatedly selecting the first element that belongs next.
/// @param data the array to sort
/// @param count the number of elements
/// @param before the ordering comparator
/// @param comparisons comparisons increased by the number of comparisons made
void selection_sort(ScoreEntry *data, int count, Comparator before,
                    long &comparisons) {
    for (int i = 0; i < count - 1; ++i) {
        int best_idx = i;
        for (int j = i + 1; j < count; ++j) {
            ++comparisons;
            if (before(data[j], data[best_idx])) {
                best_idx = j;
            }
        }
        if (best_idx != i) {
            ScoreEntry temp = data[i];
            data[i] = data[best_idx];
            data[best_idx] = temp;
        }
    }
}

/// Sort in place by inserting each element into the sorted part before it.
/// Shift elements; do not swap.
/// @pre data points to at least count valid ScoreEntry elements
/// @param data the array to sort
/// @param count the number of elements
/// @param before the ordering comparator
/// @param comparisons comparisons increased by the number of comparisons made
void insertion_sort(ScoreEntry *data, int count, Comparator before,
                    long &comparisons) {
    for (int i = 1; i < count; ++i) {
        ScoreEntry current = data[i];
        int pos = i - 1;

        while (pos >= 0) {
            ++comparisons;
            if (before(current, data[pos])) {
                data[pos + 1] = data[pos];
                --pos;
            } else {
                break;
            }
        }
        data[pos + 1] = current;
    }
}

/// Look for a name from the front.
/// @param data the array to search
/// @param count the number of elements
/// @param name the target player name
/// @param comparisons comparisons increased by the number of comparisons made
/// @return the index of the first entry with that name, or -1
int linear_search_name(const ScoreEntry *data, int count,
                       const std::string &name, long &comparisons) {
    for (int i = 0; i < count; ++i) {
        ++comparisons;
        if (data[i].name == name) {
            return i;
        }
    }
    return -1;
}

/// Look for a name by halving the range.
/// @pre data is sorted with name_ascending
/// @param data the sorted array to search
/// @param count the number of elements
/// @param name the target player name
/// @param comparisons comparisons increased by the number of comparisons made
/// @return the index of an entry with that name, or -1
int binary_search_name(const ScoreEntry *data, int count,
                       const std::string &name, long &comparisons) {
    int low = 0;
    int high = count - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        ++comparisons;
        if (data[mid].name == name) {
            return mid;
        }

        ++comparisons;
        if (name < data[mid].name) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}
