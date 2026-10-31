### Approach

Keep a min-heap holding the current front value of each list. Repeatedly pop the smallest value, append it to the result, and push the next value from the same list. The heap never holds more than k entries.

### Implementation

```python
from typing import List
import heapq


class Solution:
    def mergeKLists(self, lists: List[List[int]]) -> List[int]:
        heap = [(lst[0], i, 0) for i, lst in enumerate(lists) if lst]
        heapq.heapify(heap)
        merged = []
        while heap:
            value, i, j = heapq.heappop(heap)
            merged.append(value)
            if j + 1 < len(lists[i]):
                heapq.heappush(heap, (lists[i][j + 1], i, j + 1))
        return merged
```

### Complexity Analysis

* Time complexity: **O(N log k), where N is the total number of nodes**.
* Space complexity: **O(k) for the heap, besides the output**.
