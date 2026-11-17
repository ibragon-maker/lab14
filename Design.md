# Design Artifacts & Hand-Traces (Task 1)

## 1. Selection Sort Hand-Trace
* **Starting Array (scores descending):** `[30, 80, 10, 60, 40, 90]`
* **Pass 1 (i = 0):** Scan indices 1–5, find max `90` at index 5. Swap with index 0.
  * *Array:* `[90, 80, 10, 60, 40, 30]` | *Comparisons this pass:* 5 | *Total:* 5
* **Pass 2 (i = 1):** Scan indices 2–5, max is `80` at index 1 (already in place).
  * *Array:* `[90, 80, 10, 60, 40, 30]` | *Comparisons this pass:* 4 | *Total:* 9
* **Pass 3 (i = 2):** Scan indices 3–5, find max `60` at index 3. Swap with index 2.
  * *Array:* `[90, 80, 60, 10, 40, 30]` | *Comparisons this pass:* 3 | *Total:* 12
* **Pass 4 (i = 3):** Scan indices 4–5, find max `40` at index 4. Swap with index 3.
  * *Array:* `[90, 80, 60, 40, 10, 30]` | *Comparisons this pass:* 2 | *Total:* 14
* **Pass 5 (i = 4):** Scan index 5, find max `30` at index 5. Swap with index 4.
  * *Array:* `[90, 80, 60, 40, 30, 10]` | *Comparisons this pass:* 1 | *Total:* 15

---

## 2. Binary Search Hand-Trace
* **Sorted Array:** `["anna", "bob", "carl", "dave", "evan", "frank", "gina", "hank"]` (Indices 0–7)

### Scenario A: Searching for a Present Name (`"evan"`)
* **Iteration 1:** `low = 0`, `high = 7` $\rightarrow$ `mid = 3` (`"dave"`). Target `"evan"` > `"dave"`. Update `low = 4`. *(Comparisons: 1)*
* **Iteration 2:** `low = 4`, `high = 7` $\rightarrow$ `mid = 5` (`"frank"`). Target `"evan"` < `"frank"`. Update `high = 4`. *(Comparisons: 2)*
* **Iteration 3:** `low = 4`, `high = 4` $\rightarrow$ `mid = 4` (`"evan"`). **Match found at index 4!** *(Comparisons: 3)*

### Scenario B: Searching for a Missing Name (`"chris"`)
* **Iteration 1:** `low = 0`, `high = 7` $\rightarrow$ `mid = 3` (`"dave"`). Target `"chris"` < `"dave"`. Update `high = 2`. *(Comparisons: 1)*
* **Iteration 2:** `low = 0`, `high = 2` $\rightarrow$ `mid = 1` (`"bob"`). Target `"chris"` > `"bob"`. Update `low = 2`. *(Comparisons: 2)*
* **Iteration 3:** `low = 2`, `high = 2` $\rightarrow$ `mid = 2` (`"carl"`). Target `"chris"` < `"carl"`. Update `high = 1`. *(Comparisons: 3)*
* **Termination:** `low (2) > high (1)`. Loop exits. Returns `-1`.
