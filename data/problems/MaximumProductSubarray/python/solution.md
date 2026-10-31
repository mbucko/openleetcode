### Approach

Scan the array once while tracking two values for the subarray that ends at the current index: the largest product and the smallest product. The smallest product matters because multiplying it by a negative number can make it the new largest product. At each element, the new largest and smallest products are chosen from three candidates: the element on its own (start a new subarray), the previous largest product times the element, and the previous smallest product times the element. A zero resets both values, because the element on its own wins. The answer is the largest value the running maximum reaches.

### Implementation

```python
from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # Track both the largest and smallest product of a subarray ending
        # at the current index: a negative number turns the smallest
        # (most negative) product into the largest one.
        max_ending_here = nums[0]
        min_ending_here = nums[0]
        best = nums[0]

        for value in nums[1:]:
            candidates = (value, max_ending_here * value, min_ending_here * value)
            max_ending_here = max(candidates)
            min_ending_here = min(candidates)
            best = max(best, max_ending_here)

        return best
```

### Complexity Analysis

* Time complexity: **O(n)**, one pass over ``nums``.
* Space complexity: **O(1)**, only three running values are stored.
