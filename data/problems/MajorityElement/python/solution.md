### Approach

Boyer-Moore voting: keep a candidate and a counter. A matching value adds a vote and any other value removes one. When the counter hits zero, take the next value as the new candidate. The majority value appears more often than all the others combined, so it is the candidate at the end.

### Implementation

```python
from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        candidate = None
        count = 0

        for num in nums:
            if count == 0:
                candidate = num
            count += 1 if num == candidate else -1

        return candidate
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
