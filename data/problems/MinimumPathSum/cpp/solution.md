### Approach

The cheapest way to reach a cell comes from the cheaper of the cell above and the cell on the left, plus the cell's own value. Fill the grid row by row, keeping one row of best sums. Before a row is updated, it holds the values from the row above.

### Implementation

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int n = grid[0].size();
        vector<int> row(n, INT_MAX);
        row[0] = 0;
        for (const auto& gridRow : grid) {
            row[0] += gridRow[0];
            for (int c = 1; c < n; ++c) {
                row[c] = min(row[c], row[c - 1]) + gridRow[c];
            }
        }
        return row[n - 1];
    }
};
```

### Complexity Analysis

* Time complexity: **O(m * n)**.
* Space complexity: **O(n)**.
