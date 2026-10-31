### Approach

Peel the matrix one ring at a time, keeping four boundaries: top, bottom, left and right. Walk the top row, the right column, then the bottom row backwards and the left column upwards, and shrink all four boundaries. When only a single row or column is left, the last two walks are skipped so nothing is visited twice.

### Implementation

```python
from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        result = []
        top, bottom = 0, len(matrix) - 1
        left, right = 0, len(matrix[0]) - 1
        while top <= bottom and left <= right:
            for c in range(left, right + 1):
                result.append(matrix[top][c])
            for r in range(top + 1, bottom + 1):
                result.append(matrix[r][right])
            if top < bottom and left < right:
                for c in range(right - 1, left - 1, -1):
                    result.append(matrix[bottom][c])
                for r in range(bottom - 1, top, -1):
                    result.append(matrix[r][left])
            top, bottom, left, right = top + 1, bottom - 1, left + 1, right - 1
        return result
```

### Complexity Analysis

* Time complexity: **O(m * n)**.
* Space complexity: **O(1) extra, besides the output**.
