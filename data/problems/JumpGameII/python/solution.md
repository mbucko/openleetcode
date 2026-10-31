### Approach

Treat it as a breadth-first search over ranges. The indices reachable with k jumps form a contiguous range. While scanning that range, track the farthest index reachable from it, which is where the range for k + 1 jumps ends. Every time you pass the end of the current range, you have used one more jump.

### Implementation

```python
from typing import List


class Solution:
    def jump(self, nums: List[int]) -> int:
        jumps = 0
        current_end = 0
        farthest = 0
        for i in range(len(nums) - 1):
            farthest = max(farthest, i + nums[i])
            if i == current_end:
                jumps += 1
                current_end = farthest
        return jumps
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
