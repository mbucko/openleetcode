### Approach

Use the first row and first column as markers. Remember separately whether they contain a zero themselves. Then, for every zero elsewhere, mark its row in the first column and its column in the first row. A second pass zeroes every cell whose row or column is marked. Finally, zero the first row and column if they originally had a zero.

### Implementation

```python
from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> List[List[int]]:
        m, n = len(matrix), len(matrix[0])
        first_row_zero = any(matrix[0][c] == 0 for c in range(n))
        first_col_zero = any(matrix[r][0] == 0 for r in range(m))
        for r in range(1, m):
            for c in range(1, n):
                if matrix[r][c] == 0:
                    matrix[r][0] = 0
                    matrix[0][c] = 0
        for r in range(1, m):
            for c in range(1, n):
                if matrix[r][0] == 0 or matrix[0][c] == 0:
                    matrix[r][c] = 0
        if first_row_zero:
            for c in range(n):
                matrix[0][c] = 0
        if first_col_zero:
            for r in range(m):
                matrix[r][0] = 0
        return matrix
```

### Complexity Analysis

* Time complexity: **O(m * n)**.
* Space complexity: **O(1)**.
