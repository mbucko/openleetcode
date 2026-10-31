### Approach

Start from "1" and build each term from the previous one. Scan the previous term, find each run of equal digits, and append the run's length followed by the digit.

### Implementation

```python
class Solution:
    def countAndSay(self, n: int) -> str:
        term = "1"
        for _ in range(n - 1):
            parts = []
            i = 0
            while i < len(term):
                j = i
                while j < len(term) and term[j] == term[i]:
                    j += 1
                parts.append(str(j - i) + term[i])
                i = j
            term = "".join(parts)
        return term
```

### Complexity Analysis

* Time complexity: **O(n * L), where L is the length of the longest term**.
* Space complexity: **O(L)**.
