### Approach

A scramble of s1 into s2 splits s1 at some position k. Either the two parts stay in order and match the first k and last n - k characters of s2, or they were swapped and match the last k and first n - k. Check both options recursively for every k. Memoising on the pair of substrings (or using a table indexed by length and start positions) keeps it polynomial, and the Python version also rejects pairs with different letters early.

### Implementation

```python
from functools import lru_cache


class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        @lru_cache(maxsize=None)
        def scramble(a, b):
            if a == b:
                return True
            if sorted(a) != sorted(b):
                return False
            n = len(a)
            for i in range(1, n):
                if scramble(a[:i], b[:i]) and scramble(a[i:], b[i:]):
                    return True
                if scramble(a[:i], b[n - i:]) and scramble(a[i:], b[:n - i]):
                    return True
            return False

        return scramble(s1, s2)
```

### Complexity Analysis

* Time complexity: **O(n^4)**.
* Space complexity: **O(n^3)**.
