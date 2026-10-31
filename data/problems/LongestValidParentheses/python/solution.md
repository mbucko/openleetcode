### Approach

Keep a stack of indices. Its bottom always holds the position just before the current balanced run, starting at -1. Push the index of each '('. A ')' pops one entry. If the stack becomes empty, this ')' is unmatched, so it becomes the new base. Otherwise the balanced run ending here started right after the index now on top.

### Implementation

```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack = [-1]
        best = 0
        for i, ch in enumerate(s):
            if ch == "(":
                stack.append(i)
            else:
                stack.pop()
                if not stack:
                    stack.append(i)
                else:
                    best = max(best, i - stack[-1])
        return best
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(n)**.
