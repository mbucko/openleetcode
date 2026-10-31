### Approach

The same backtracking as listing the placements, but only counting them. Place one queen per row and track the used columns and both diagonals (row - col and row + col). The C++ version keeps them as bit masks.

### Implementation

```python
class Solution:
    def totalNQueens(self, n: int) -> int:
        def count(row, cols, diag, anti):
            if row == n:
                return 1
            total = 0
            for col in range(n):
                if col in cols or row - col in diag or row + col in anti:
                    continue
                total += count(row + 1, cols | {col}, diag | {row - col}, anti | {row + col})
            return total

        return count(0, frozenset(), frozenset(), frozenset())
```

### Complexity Analysis

* Time complexity: **O(n!)**.
* Space complexity: **O(n) recursion depth**.
