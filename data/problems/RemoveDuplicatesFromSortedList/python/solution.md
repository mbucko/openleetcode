### Approach

Walk the list once. A node whose value equals the previous kept node's value is a duplicate and is skipped. With real nodes, that means linking the current node straight to the following one.

### Implementation

```python
from typing import List


class Solution:
    def deleteDuplicates(self, head: List[int]) -> List[int]:
        result = []
        for value in head:
            if not result or result[-1] != value:
                result.append(value)
        return result
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1) extra, besides the output**.
