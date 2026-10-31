### Approach

From the right, find the first position i where nums[i] < nums[i + 1]. Everything after i is in descending order, the last arrangement of that suffix. Swap nums[i] with the smallest value to its right that is larger than it, then reverse the suffix so it becomes ascending, its first arrangement. If no such i exists, the whole array is descending, and reversing it gives the first permutation.

### Implementation

```python
from typing import List


class Solution:
    def nextPermutation(self, nums: List[int]) -> List[int]:
        i = len(nums) - 2
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1
        if i >= 0:
            j = len(nums) - 1
            while nums[j] <= nums[i]:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]
        nums[i + 1:] = reversed(nums[i + 1:])
        return nums
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
