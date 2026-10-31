### Approach

Add from the last digit. A 9 becomes 0 and the carry moves left. Any other digit just goes up by one and you're done. If every digit was 9, they are all 0 now, so put a 1 in front.

### Implementation

```python
from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        for i in range(len(digits) - 1, -1, -1):
            if digits[i] < 9:
                digits[i] += 1
                return digits
            digits[i] = 0
        return [1] + digits
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1) extra, besides a possible new leading digit**.
