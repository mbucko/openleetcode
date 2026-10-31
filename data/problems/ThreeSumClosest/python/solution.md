### Approach

Sort the array. For each first value, scan the rest with two pointers. A sum that is too small moves the left pointer right, and one that is too large moves the right pointer left. Keep the sum closest to the target, and stop early on an exact hit.

### Implementation

```python
from typing import List


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums = sorted(nums)
        best = nums[0] + nums[1] + nums[2]
        for i in range(len(nums) - 2):
            left, right = i + 1, len(nums) - 1
            while left < right:
                total = nums[i] + nums[left] + nums[right]
                if abs(total - target) < abs(best - target):
                    best = total
                if total < target:
                    left += 1
                elif total > target:
                    right -= 1
                else:
                    return total
        return best
```

### Complexity Analysis

* Time complexity: **O(n^2)**.
* Space complexity: **O(log n) to O(n) for sorting**.
