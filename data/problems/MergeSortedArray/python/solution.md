### Approach

Fill nums1 from the back. Compare the largest remaining values of the two arrays and write the larger one into the last unfilled slot. Writing from the back never overwrites a value of nums1 that hasn't been read yet. When nums2 runs out, the rest of nums1 is already in place.

### Implementation

```python
from typing import List


class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> List[int]:
        i, j, k = m - 1, n - 1, m + n - 1
        while j >= 0:
            if i >= 0 and nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1
        return nums1
```

### Complexity Analysis

* Time complexity: **O(m + n)**.
* Space complexity: **O(1)**.
