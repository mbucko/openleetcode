### Approach

Two pointers moving inwards, each tracking the tallest bar seen on its side. Always move the side whose current bar is shorter. There is a taller bar on the other side, so that side's tallest bar so far is what limits the water, and the water above the current bar is that maximum minus its height.

### Implementation

```python
from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        left, right = 0, len(height) - 1
        left_max = right_max = 0
        water = 0
        while left < right:
            if height[left] < height[right]:
                left_max = max(left_max, height[left])
                water += left_max - height[left]
                left += 1
            else:
                right_max = max(right_max, height[right])
                water += right_max - height[right]
                right -= 1
        return water
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
