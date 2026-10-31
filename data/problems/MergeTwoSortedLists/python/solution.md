### Approach

Walk both lists with one pointer each. Repeatedly take the smaller of the two current values and advance that pointer. When one list runs out, the rest of the other list is already sorted, so append it.

### Implementation

```python
from typing import List


class Solution:
    def mergeTwoLists(self, list1: List[int], list2: List[int]) -> List[int]:
        merged = []
        i = j = 0
        while i < len(list1) and j < len(list2):
            if list1[i] <= list2[j]:
                merged.append(list1[i])
                i += 1
            else:
                merged.append(list2[j])
                j += 1
        return merged + list1[i:] + list2[j:]
```

### Complexity Analysis

* Time complexity: **O(m + n)**.
* Space complexity: **O(1) extra, besides the output**.
