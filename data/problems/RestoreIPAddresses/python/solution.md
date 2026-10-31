### Approach

Backtracking over where the dots go. Take the next number as 1, 2 or 3 digits, as long as it has no leading zero and is at most 255, and recurse. A candidate is complete when there are exactly four numbers and every digit has been used. Sort the addresses at the end.

### Implementation

```python
from typing import List


class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        result = []
        parts = []

        def build(start):
            if len(parts) == 4:
                if start == len(s):
                    result.append(".".join(parts))
                return
            for length in range(1, 4):
                piece = s[start:start + length]
                if len(piece) < length:
                    break
                if (piece[0] == "0" and length > 1) or int(piece) > 255:
                    break
                parts.append(piece)
                build(start + length)
                parts.pop()

        build(0)
        return sorted(result)
```

### Complexity Analysis

* Time complexity: **O(1), at most 3^4 ways to split**.
* Space complexity: **O(1) besides the output**.
