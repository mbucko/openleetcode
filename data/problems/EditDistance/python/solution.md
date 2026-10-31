### Approach

Dynamic programming: d[i][j] is the distance between the first i characters of word1 and the first j of word2. If the last characters match, d[i][j] = d[i-1][j-1]. Otherwise take 1 plus the best of replace (d[i-1][j-1]), delete (d[i-1][j]) and insert (d[i][j-1]). Only the previous row is needed at any time.

### Implementation

```python
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m, n = len(word1), len(word2)
        prev = list(range(n + 1))
        for i in range(1, m + 1):
            cur = [i] + [0] * n
            for j in range(1, n + 1):
                if word1[i - 1] == word2[j - 1]:
                    cur[j] = prev[j - 1]
                else:
                    cur[j] = 1 + min(prev[j - 1], prev[j], cur[j - 1])
            prev = cur
        return prev[n]
```

### Complexity Analysis

* Time complexity: **O(m * n)**.
* Space complexity: **O(n)**.
