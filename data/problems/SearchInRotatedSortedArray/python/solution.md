### Approach

Binary search. At every step at least one half around mid is sorted, and comparing nums[left] with nums[mid] tells you which. If the target falls inside the sorted half's range, search that half. Otherwise search the other half.

### Implementation

```python
from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            if nums[left] <= nums[mid]:
                if nums[left] <= target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            else:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
        return -1
```

### Complexity Analysis

* Time complexity: **O(log n)**.
* Space complexity: **O(1)**.
