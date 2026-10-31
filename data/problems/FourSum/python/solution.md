### Approach

Sort the array, fix the first two values with nested loops (skipping repeats), and find the remaining pair with two pointers, the same way as 3Sum. Sums of four values can pass the 32-bit range, so C++ adds them as 64-bit integers.

### Implementation

```python
from typing import List


class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums = sorted(nums)
        n = len(nums)
        result = []
        for i in range(n - 3):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            for j in range(i + 1, n - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                left, right = j + 1, n - 1
                while left < right:
                    total = nums[i] + nums[j] + nums[left] + nums[right]
                    if total < target:
                        left += 1
                    elif total > target:
                        right -= 1
                    else:
                        result.append([nums[i], nums[j], nums[left], nums[right]])
                        left += 1
                        while left < right and nums[left] == nums[left - 1]:
                            left += 1
                        right -= 1
        return result
```

### Complexity Analysis

* Time complexity: **O(n^3)**.
* Space complexity: **O(log n) to O(n) for sorting**.
