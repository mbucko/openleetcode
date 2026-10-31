### Approach

Sliding window. Count how many of each character t still needs, plus the total still missing. Grow the window to the right, and each character that was still needed lowers the missing count. When nothing is missing, the window is valid: record it, then shrink from the left until removing a character makes it invalid again.

### Implementation

```python
from collections import Counter


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        need = Counter(t)
        missing = len(t)
        best_start, best_len = 0, float("inf")
        left = 0
        for right, ch in enumerate(s):
            if need[ch] > 0:
                missing -= 1
            need[ch] -= 1
            while missing == 0:
                if right - left + 1 < best_len:
                    best_start, best_len = left, right - left + 1
                need[s[left]] += 1
                if need[s[left]] > 0:
                    missing += 1
                left += 1
        return "" if best_len == float("inf") else s[best_start:best_start + best_len]
```

### Complexity Analysis

* Time complexity: **O(m + n)**.
* Space complexity: **O(1), the alphabet is fixed**.
