### Approach

Three phases in one pass. Copy every interval that ends before the new one starts. Then absorb every interval that starts no later than the new one ends, widening the new interval as you go. Finally, add the merged interval and copy the rest.

### Implementation

```python
from typing import List


class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        result = []
        start, end = newInterval
        i = 0
        while i < len(intervals) and intervals[i][1] < start:
            result.append(intervals[i])
            i += 1
        while i < len(intervals) and intervals[i][0] <= end:
            start = min(start, intervals[i][0])
            end = max(end, intervals[i][1])
            i += 1
        result.append([start, end])
        result.extend(intervals[i:])
        return result
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(n) for the output**.
