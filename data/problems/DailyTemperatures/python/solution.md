# Approach

Iterate through the array once while keeping a stack of indices whose temperatures are still waiting for a warmer day. For each element, pop every index on the stack with a lower temperature and record the distance to the current day. Then push the current index and continue.

## Implementation

```python
from typing import List


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        answer = [0] * len(temperatures)
        stack = []

        for index, value in enumerate(temperatures):
            while stack and temperatures[stack[-1]] < value:
                prev = stack.pop()
                answer[prev] = index - prev
            stack.append(index)

        return answer
```

## Complexity Analysis

* Time complexity: **O(n)**
* Space complexity: **O(n)**
