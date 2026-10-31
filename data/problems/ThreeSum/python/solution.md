### Approach

Sort the array. For each first value (skipping repeats), look for pairs in the rest of the array that cancel it out using two pointers: move the left pointer right if the sum is too small, and the right pointer left if it is too big. After a match, skip repeated values so no triplet is listed twice. Because the array is sorted, the triplets come out in the required order.

### Implementation

```python
from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        result = []
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            left, right = i + 1, len(nums) - 1
            while left < right:
                total = nums[i] + nums[left] + nums[right]
                if total < 0:
                    left += 1
                elif total > 0:
                    right -= 1
                else:
                    result.append([nums[i], nums[left], nums[right]])
                    left += 1
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
                    right -= 1
        return result
```

### Complexity Analysis

* Time complexity: **O(n^2)**.
* Space complexity: **O(log n) to O(n) for sorting**.
