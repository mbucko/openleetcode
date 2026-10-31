### Approach

The answer is at most n + 1, so only the values 1 to n matter. Use the array itself as a lookup table: keep swapping each value v in that range into position v - 1. Each swap puts one value into its final place, so this takes O(n) in total. Afterwards, the first position i that doesn't hold i + 1 gives the answer. If every position matches, the answer is n + 1.

### Implementation

```python
from typing import List


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            while 1 <= nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                j = nums[i] - 1
                nums[i], nums[j] = nums[j], nums[i]
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1
        return n + 1
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
