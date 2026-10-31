### Approach

Dynamic programming over suffixes: dp[i][j] says whether s[i:] matches p[j:]. If p[j] is followed by '*', either skip that pair entirely (dp[i][j + 2]), or, when the current characters match, use one copy and stay on the same pattern position (dp[i + 1][j]). Otherwise the current characters must match and both move forward.

### Implementation

```python
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m, n = len(s), len(p)
        dp = [[False] * (n + 1) for _ in range(m + 1)]
        dp[m][n] = True
        for i in range(m, -1, -1):
            for j in range(n - 1, -1, -1):
                first = i < m and p[j] in (s[i], ".")
                if j + 1 < n and p[j + 1] == "*":
                    dp[i][j] = dp[i][j + 2] or (first and dp[i + 1][j])
                else:
                    dp[i][j] = first and dp[i + 1][j + 1]
        return dp[0][0]
```

### Complexity Analysis

* Time complexity: **O(m * n)**.
* Space complexity: **O(m * n)**.
