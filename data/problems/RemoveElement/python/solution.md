### Approach

Keep a write position k. Scan the array and copy every value that is not val to position k, then advance k. Values equal to val are skipped, so the kept values stay in their original order.

### Implementation

```python
from typing import List


class Solution:
    def removeElement(self, nums: List[int], val: int) -> List[int]:
        k = 0
        for num in nums:
            if num != val:
                nums[k] = num
                k += 1
        return nums[:k]
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
