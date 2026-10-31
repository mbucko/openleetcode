### Approach

Start with the two outermost walls, the widest container possible. The shorter wall limits the water, and moving the taller wall inwards can never help, because the width shrinks and the height is still capped by the shorter wall. So always move the shorter wall inwards, and track the best area along the way.

### Implementation

```python
from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        left, right = 0, len(height) - 1
        best = 0
        while left < right:
            best = max(best, min(height[left], height[right]) * (right - left))
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return best
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
