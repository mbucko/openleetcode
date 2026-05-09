### Approach

Scan the grid. Each time a land cell is found, run a breadth-first flood fill to sink the whole island.

### Implementation

```python
from collections import deque
from typing import List


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        def sink_island(start_i, start_j):
            pairs = deque([(start_i, start_j)])

            while pairs:
                i, j = pairs.popleft()

                if grid[i][j] == "0":
                    continue
                grid[i][j] = "0"

                if i > 0:
                    pairs.append((i - 1, j))
                if j > 0:
                    pairs.append((i, j - 1))
                if i + 1 < len(grid):
                    pairs.append((i + 1, j))
                if j + 1 < len(grid[0]):
                    pairs.append((i, j + 1))

        n_islands = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1":
                    n_islands += 1
                    sink_island(i, j)

        return n_islands
```

### Complexity Analysis

* Time complexity: **O(M*N)**.
* Space complexity: **O(M*N)**.
