### Approach

The same binary search as without duplicates: find the sorted half and check whether the target falls in its range. The one new case is when the left, middle and right values are all equal. Then you can't tell which half is sorted, so drop both ends and continue. That case is what makes the worst case linear.

### Implementation

```python
from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return True
            if nums[left] == nums[mid] == nums[right]:
                left += 1
                right -= 1
            elif nums[left] <= nums[mid]:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        return False
```

### Complexity Analysis

* Time complexity: **O(log n) on average, O(n) in the worst case**.
* Space complexity: **O(1)**.
