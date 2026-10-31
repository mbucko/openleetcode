### Approach

Binary search for a split of the shorter array. Taking i values from it and half - i from the other array puts exactly half of all values on the left. The split is correct when every value on the left is no larger than every value on the right. The median then comes from the largest left value, and for an even total also the smallest right value.

### Implementation

```python
from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        a, b = nums1, nums2
        if len(a) > len(b):
            a, b = b, a
        m, n = len(a), len(b)
        half = (m + n + 1) // 2
        low, high = 0, m
        while True:
            i = (low + high) // 2
            j = half - i
            a_left = a[i - 1] if i > 0 else float("-inf")
            a_right = a[i] if i < m else float("inf")
            b_left = b[j - 1] if j > 0 else float("-inf")
            b_right = b[j] if j < n else float("inf")
            if a_left <= b_right and b_left <= a_right:
                if (m + n) % 2:
                    return float(max(a_left, b_left))
                return (max(a_left, b_left) + min(a_right, b_right)) / 2
            if a_left > b_right:
                high = i - 1
            else:
                low = i + 1
```

### Complexity Analysis

* Time complexity: **O(log(min(m, n)))**.
* Space complexity: **O(1)**.
