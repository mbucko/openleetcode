### Approach

Greedy matching with backtracking to the most recent '*'. Match characters and '?' directly. When you meet a '*', remember where it is and first let it match nothing. On a later mismatch, go back and let that '*' absorb one more character. Only the latest '*' ever needs revisiting, because it can stretch to cover anything an earlier one could.

### Implementation

```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        i = j = 0
        star = -1
        match = 0
        while i < len(s):
            if j < len(p) and p[j] in (s[i], "?"):
                i += 1
                j += 1
            elif j < len(p) and p[j] == "*":
                star = j
                match = i
                j += 1
            elif star != -1:
                j = star + 1
                match += 1
                i = match
            else:
                return False
        while j < len(p) and p[j] == "*":
            j += 1
        return j == len(p)
```

### Complexity Analysis

* Time complexity: **O(m * n) in the worst case, usually close to linear**.
* Space complexity: **O(1)**.
