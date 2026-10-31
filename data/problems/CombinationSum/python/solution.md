### Approach

Sort the candidates and backtrack. At each step, try every candidate from the current position onwards. Staying at the same position lets a candidate repeat, and never going back to an earlier one prevents listing the same combination twice. Stop early once a candidate is larger than what is left. Trying candidates in ascending order gives the required ordering.

### Implementation

```python
from typing import List


class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates = sorted(candidates)
        result = []
        current = []

        def build(start, remaining):
            if remaining == 0:
                result.append(list(current))
                return
            for i in range(start, len(candidates)):
                if candidates[i] > remaining:
                    break
                current.append(candidates[i])
                build(i, remaining - candidates[i])
                current.pop()

        build(0, target)
        return result
```

### Complexity Analysis

* Time complexity: **Exponential in target / min(candidates)**.
* Space complexity: **O(target / min(candidates)) recursion depth, besides the output**.
