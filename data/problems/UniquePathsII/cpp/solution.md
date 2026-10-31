### Approach

Same recurrence as without obstacles: paths to a cell = paths to the cell above + paths to the cell on the left, except that a blocked cell has zero paths. Keep one row of counts and update it in place. Seeding the start with 1 handles a blocked start automatically, because the first row overwrites it with 0.

### Implementation

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int n = obstacleGrid[0].size();
        vector<long long> row(n, 0);
        row[0] = 1;
        for (const auto& gridRow : obstacleGrid) {
            for (int c = 0; c < n; ++c) {
                if (gridRow[c] == 1) {
                    row[c] = 0;
                } else if (c > 0) {
                    row[c] += row[c - 1];
                }
            }
        }
        return static_cast<int>(row[n - 1]);
    }
};
```

### Complexity Analysis

* Time complexity: **O(m * n)**.
* Space complexity: **O(n)**.
