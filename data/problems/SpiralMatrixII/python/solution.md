### Approach

Walk the spiral directly. Move in the current direction (right, down, left, up), writing the next number into each cell. When the next step would leave the matrix or land on a filled cell, turn clockwise.

### Implementation

```python
from typing import List


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        matrix = [[0] * n for _ in range(n)]
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        r = c = d = 0
        for value in range(1, n * n + 1):
            matrix[r][c] = value
            dr, dc = directions[d]
            if not (0 <= r + dr < n and 0 <= c + dc < n and matrix[r + dr][c + dc] == 0):
                d = (d + 1) % 4
                dr, dc = directions[d]
            r, c = r + dr, c + dc
        return matrix
```

### Complexity Analysis

* Time complexity: **O(n^2)**.
* Space complexity: **O(1) extra, besides the output**.
