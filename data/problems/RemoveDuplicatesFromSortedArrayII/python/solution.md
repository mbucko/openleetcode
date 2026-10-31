### Approach

Keep a write position k. A value may be written if fewer than two values have been kept so far, or if it differs from the value kept two places back. Since the array is sorted, being equal to that value would mean it is a third copy.

### Implementation

```python
from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> List[int]:
        k = 0
        for num in nums:
            if k < 2 or num != nums[k - 2]:
                nums[k] = num
                k += 1
        return nums[:k]
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
