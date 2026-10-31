### Approach

Build two chains while walking the list once: one for nodes less than x and one for the rest, each appended in the order the nodes are seen. Then attach the second chain to the end of the first. With real nodes this is just relinking, using two dummy heads.

### Implementation

```python
from typing import List


class Solution:
    def partition(self, head: List[int], x: int) -> List[int]:
        before = [v for v in head if v < x]
        after = [v for v in head if v >= x]
        return before + after
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1) extra with real nodes**.
