### Approach

The number of paths to a cell is the number of paths to the cell above plus the number to the cell on the left. Cells in the first row or column have exactly one path. Fill the grid row by row, keeping only one row of counts.

### Implementation

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<long long> row(n, 1);
        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                row[c] += row[c - 1];
            }
        }
        return static_cast<int>(row[n - 1]);
    }
};
```

### Complexity Analysis

* Time complexity: **O(m * n)**.
* Space complexity: **O(n)**.
