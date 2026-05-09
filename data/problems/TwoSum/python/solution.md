### Approach

Iterate through the array once. For each element, check if the target minus the current element exists in a hash map. If it does, return the matching pair of indices. Otherwise, store the current value and continue.

### Implementation

```python
from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        visited = {}

        for index, value in enumerate(nums):
            delta = target - value
            if delta in visited:
                return [visited[delta], index]
            visited[value] = index

        return []
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(n)**.
