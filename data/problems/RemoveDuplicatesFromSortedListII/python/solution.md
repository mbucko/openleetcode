### Approach

Equal values sit next to each other in a sorted list, so walk it one run of equal values at a time and keep a value only if its run has length one. With real nodes, keep a pointer to the last kept node (starting from a dummy head) and link it past any run longer than one.

### Implementation

```python
from typing import List


class Solution:
    def deleteDuplicates(self, head: List[int]) -> List[int]:
        result = []
        i = 0
        while i < len(head):
            j = i
            while j < len(head) and head[j] == head[i]:
                j += 1
            if j - i == 1:
                result.append(head[i])
            i = j
        return result
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1) extra, besides the output**.
