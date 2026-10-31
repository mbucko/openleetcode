### Approach

Push opening brackets onto a stack. A closing bracket must match the bracket on top of the stack, which is the most recently opened one, and that bracket is popped. The string is valid if every closing bracket matched and the stack ends empty.

### Implementation

```python
class Solution:
    def isValid(self, s: str) -> bool:
        pairs = {")": "(", "]": "[", "}": "{"}
        stack = []
        for ch in s:
            if ch in pairs:
                if not stack or stack.pop() != pairs[ch]:
                    return False
            else:
                stack.append(ch)
        return not stack
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(n)**.
