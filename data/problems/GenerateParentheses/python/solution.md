### Approach

Backtracking. Build the string one character at a time: you may add '(' while fewer than n have been used, and ')' while it would close an open one. Every complete string built this way is balanced. Trying '(' before ')' produces the strings in lexicographic order.

### Implementation

```python
from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []

        def build(current, opened, closed):
            if len(current) == 2 * n:
                result.append(current)
                return
            if opened < n:
                build(current + "(", opened + 1, closed)
            if closed < opened:
                build(current + ")", opened, closed + 1)

        build("", 0, 0)
        return result
```

### Complexity Analysis

* Time complexity: **O(4^n / sqrt(n)), the number of valid strings**.
* Space complexity: **O(n) recursion depth, besides the output**.
