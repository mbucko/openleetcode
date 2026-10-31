### Approach

Place one queen per row with backtracking. Track the used columns and both kinds of diagonal: row - col is constant along one direction and row + col along the other, so each check takes constant time. Trying columns left to right gives the required ordering.

### Implementation

```python
from typing import List


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        result = []
        columns = []
        used_cols, used_diag, used_anti = set(), set(), set()

        def place(row):
            if row == n:
                result.append(["." * c + "Q" + "." * (n - c - 1) for c in columns])
                return
            for col in range(n):
                if col in used_cols or row - col in used_diag or row + col in used_anti:
                    continue
                columns.append(col)
                used_cols.add(col)
                used_diag.add(row - col)
                used_anti.add(row + col)
                place(row + 1)
                columns.pop()
                used_cols.remove(col)
                used_diag.remove(row - col)
                used_anti.remove(row + col)

        place(0)
        return result
```

### Complexity Analysis

* Time complexity: **O(n!)**.
* Space complexity: **O(n) besides the output**.
