### Approach

Same recurrence as without obstacles: paths to a cell = paths to the cell above + paths to the cell on the left, except that a blocked cell has zero paths. Keep one row of counts and update it in place. Seeding the start with 1 handles a blocked start automatically, because the first row overwrites it with 0.

### Implementation

```python
from typing import List


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        n = len(obstacleGrid[0])
        row = [0] * n
        row[0] = 1
        for grid_row in obstacleGrid:
            for c in range(n):
                if grid_row[c] == 1:
                    row[c] = 0
                elif c > 0:
                    row[c] += row[c - 1]
        return row[-1]
```

### Complexity Analysis

* Time complexity: **O(m * n)**.
* Space complexity: **O(n)**.
