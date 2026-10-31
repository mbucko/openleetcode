### Approach

Treat each row as the floor of a histogram, where a column's bar height is the number of consecutive 1s ending at that row. Each row's histogram is updated from the previous one in O(n). Then find its largest rectangle with the monotonic-stack method from Largest Rectangle in Histogram, and keep the best over all rows.

### Implementation

```python
from typing import List


class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        heights = [0] * len(matrix[0])
        best = 0
        for row in matrix:
            for c, cell in enumerate(row):
                heights[c] = heights[c] + 1 if cell == "1" else 0
            stack = []
            for i, h in enumerate(heights + [0]):
                start = i
                while stack and stack[-1][1] >= h:
                    index, height = stack.pop()
                    best = max(best, height * (i - index))
                    start = index
                stack.append((start, h))
        return best
```

### Complexity Analysis

* Time complexity: **O(m * n)**.
* Space complexity: **O(n)**.
