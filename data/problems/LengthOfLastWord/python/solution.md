### Approach

Scan from the end. Skip trailing spaces, then count characters until the next space or the start of the string.

### Implementation

```python
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        i = len(s) - 1
        while s[i] == " ":
            i -= 1
        length = 0
        while i >= 0 and s[i] != " ":
            length += 1
            i -= 1
        return length
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
