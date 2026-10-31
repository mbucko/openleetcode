### Approach

Keep a stack of bars with increasing heights, each paired with the leftmost index its rectangle can start from. When a shorter bar arrives, every taller bar on the stack can't extend any further right, so pop them and measure their rectangles. The new bar takes over the start index of the last bar popped. A height-0 bar at the end flushes the stack.

### Implementation

```python
from typing import List


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        best = 0
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

* Time complexity: **O(n)**.
* Space complexity: **O(n)**.
