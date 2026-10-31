### Approach

Binary search, comparing the middle element with the rightmost one. If the middle is larger, the rotation point (the minimum) is to its right. Otherwise the minimum is at the middle or to its left.

### Implementation

```python
from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1

        while left < right:
            mid = (left + right) // 2

            if nums[mid] > nums[right]:
                left = mid + 1
            else:
                right = mid

        return nums[left]
```

### Complexity Analysis

* Time complexity: **O(log n)**.
* Space complexity: **O(1)**.
