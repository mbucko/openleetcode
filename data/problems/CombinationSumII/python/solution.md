### Approach

Sort the candidates and backtrack, moving past each candidate once it is used. To avoid repeated combinations, skip a value at a given depth if the same value was already tried at that depth (i > start and it equals the previous value). The first copy already covers every combination that uses it.

### Implementation

```python
from typing import List


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
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
                if i > start and candidates[i] == candidates[i - 1]:
                    continue
                current.append(candidates[i])
                build(i + 1, remaining - candidates[i])
                current.pop()

        build(0, target)
        return result
```

### Complexity Analysis

* Time complexity: **O(2^n) in the worst case**.
* Space complexity: **O(n) recursion depth, besides the output**.
