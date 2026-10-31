### Approach

Use the first row and first column as markers. Remember separately whether they contain a zero themselves. Then, for every zero elsewhere, mark its row in the first column and its column in the first row. A second pass zeroes every cell whose row or column is marked. Finally, zero the first row and column if they originally had a zero.

### Implementation

```cpp
class Solution {
public:
    vector<vector<int>> setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        bool firstRowZero = false;
        bool firstColZero = false;
        for (int c = 0; c < n; ++c) {
            firstRowZero = firstRowZero || matrix[0][c] == 0;
        }
        for (int r = 0; r < m; ++r) {
            firstColZero = firstColZero || matrix[r][0] == 0;
        }
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                if (matrix[r][0] == 0 || matrix[0][c] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }
        if (firstRowZero) {
            for (int c = 0; c < n; ++c) {
                matrix[0][c] = 0;
            }
        }
        if (firstColZero) {
            for (int r = 0; r < m; ++r) {
                matrix[r][0] = 0;
            }
        }
        return matrix;
    }
};
```

### Complexity Analysis

* Time complexity: **O(m * n)**.
* Space complexity: **O(1)**.
