### Approach

Sort the intervals by start. Walk through them, comparing each with the last merged interval. If it starts no later than that interval ends, they overlap, so extend the end. Otherwise start a new merged interval.

### Implementation

```python
from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        merged = []
        for start, end in sorted(intervals):
            if merged and start <= merged[-1][1]:
                merged[-1][1] = max(merged[-1][1], end)
            else:
                merged.append([start, end])
        return merged
```

### Complexity Analysis

* Time complexity: **O(n log n)**.
* Space complexity: **O(n) for the output**.
