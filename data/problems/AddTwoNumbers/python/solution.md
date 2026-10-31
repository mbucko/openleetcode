### Approach

Walk both lists together from the least significant digit, the way you add numbers on paper. Each position adds the two digits and the carry, keeps the last digit of that sum and carries the rest. Keep going while either list has digits left or a carry remains.

### Implementation

```python
from typing import List


class Solution:
    def addTwoNumbers(self, l1: List[int], l2: List[int]) -> List[int]:
        result = []
        carry = 0
        i = 0
        while i < len(l1) or i < len(l2) or carry:
            total = carry
            if i < len(l1):
                total += l1[i]
            if i < len(l2):
                total += l2[i]
            result.append(total % 10)
            carry = total // 10
            i += 1
        return result
```

### Complexity Analysis

* Time complexity: **O(max(m, n))**.
* Space complexity: **O(1) extra, besides the output**.
