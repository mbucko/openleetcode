### Approach

Keep a write position k that marks the end of the distinct prefix. Scan the array, and whenever a value differs from the last value written, copy it to position k and advance k. The array is sorted, so equal values are always next to each other.

### Implementation

```python
from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> List[int]:
        k = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[k - 1]:
                nums[k] = nums[i]
                k += 1
        return nums[:k]
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
