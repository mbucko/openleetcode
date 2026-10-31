### Approach

Each ``answer[i]`` is the product of everything to the left of ``i`` times the product of everything to the right of ``i``. Make a forward pass that writes the running prefix product into ``answer``, then a backward pass that multiplies each entry by the running suffix product. No division is used, so zeros in the input need no special handling.

### Implementation

```python
from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        answer = [1] * n

        prefix = 1
        for i in range(n):
            answer[i] = prefix
            prefix *= nums[i]

        suffix = 1
        for i in range(n - 1, -1, -1):
            answer[i] *= suffix
            suffix *= nums[i]

        return answer
```

### Complexity Analysis

* Time complexity: **O(n)**, two passes over the array.
* Space complexity: **O(1)** extra space, the output array is not counted.
