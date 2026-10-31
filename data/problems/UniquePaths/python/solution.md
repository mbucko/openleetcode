### Approach

The number of paths to a cell is the number of paths to the cell above plus the number to the cell on the left. Cells in the first row or column have exactly one path. Fill the grid row by row, keeping only one row of counts.

### Implementation

```python
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        row = [1] * n
        for _ in range(1, m):
            for c in range(1, n):
                row[c] += row[c - 1]
        return row[-1]
```

### Complexity Analysis

* Time complexity: **O(m * n)**.
* Space complexity: **O(n)**.
