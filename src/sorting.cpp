// =---- yours (Lab 14) ----------------------------------------------------
// Each function below is a stub so the program builds. Replace the bodies.
// Counting convention: see sorting.h.

/// Sort in place by repeatedly selecting the first element that belongs next.
/// @param data the array to sort
/// @param count the number of elements
/// @param before the ordering comparator
/// @param comparisons comparisons increased by the number of comparisons made
void selection_sort(ScoreEntry *data, int count, Comparator before,
                    long &comparisons) {
    for (int i = 0; i < count - 1; ++i) {
        int min_or_max_idx = i;
        for (int j = i + 1; j < count; ++j) {
            // Count every element comparison via the Comparator
            ++comparisons;
            if (before(data[j], data[min_or_max_idx])) {
                min_or_max_idx = j;
            }
        }
        if (min_or_max_idx != i) {
            ScoreEntry temp = data[i];
            data[i] = data[min_or_max_idx];
            data[min_or_max_idx] = temp;
        }
    }
}

/// Look for a name from the front.
/// @return the index of the first entry with that name, or -1
int linear_search_name(const ScoreEntry *data, int count,
                       const std::string &name, long &comparisons) {
    for (int i = 0; i < count; ++i) {
        // Count name comparisons
        ++comparisons;
        if (data[i].name == name) {
            return i;
        }
    }
    return -1;
}

/// Look for a name by halving the range.
/// @pre data is sorted with name_ascending
/// @return the index of an entry with that name, or -1
int binary_search_name(const ScoreEntry *data, int count,
                       const std::string &name, long &comparisons) {
    int low = 0;
    int high = count - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Count comparison between data[mid].name and name
        ++comparisons;
        if (data[mid].name == name) {
            return mid;
        }

        // Count comparison to determine direction (using name_ascending logic via comparator or direct string comparison)
        ++comparisons;
        if (name < data[mid].name) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}
