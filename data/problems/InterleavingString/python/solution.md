### Approach

Dynamic programming: dp[i][j] says whether the first i characters of s1 and the first j of s2 can interleave into the first i + j characters of s3. That is true if the last character came from s1 (dp[i-1][j] and s1[i-1] matches) or from s2 (dp[i][j-1] and s2[j-1] matches). Keep a single row and update it in place.

### Implementation

```python
class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        m, n = len(s1), len(s2)
        if m + n != len(s3):
            return False
        dp = [False] * (n + 1)
        for i in range(m + 1):
            for j in range(n + 1):
                if i == 0 and j == 0:
                    dp[j] = True
                else:
                    from_s1 = i > 0 and dp[j] and s1[i - 1] == s3[i + j - 1]
                    from_s2 = j > 0 and dp[j - 1] and s2[j - 1] == s3[i + j - 1]
                    dp[j] = from_s1 or from_s2
        return dp[n]
```

### Complexity Analysis

* Time complexity: **O(m * n)**.
* Space complexity: **O(n)**.
