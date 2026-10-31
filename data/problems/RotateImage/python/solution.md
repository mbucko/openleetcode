### Approach

A clockwise rotation is a transpose (flip across the main diagonal) followed by reversing each row. Both steps only swap elements, so they need no extra matrix.

### Implementation

```python
from typing import List


class Solution:
    def rotate(self, matrix: List[List[int]]) -> List[List[int]]:
        n = len(matrix)
        for i in range(n):
            for j in range(i + 1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        for row in matrix:
            row.reverse()
        return matrix
```

### Complexity Analysis

* Time complexity: **O(n^2)**.
* Space complexity: **O(1)**.
