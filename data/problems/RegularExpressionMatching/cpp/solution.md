### Approach

Dynamic programming over suffixes: dp[i][j] says whether s[i:] matches p[j:]. If p[j] is followed by '*', either skip that pair entirely (dp[i][j + 2]), or, when the current characters match, use one copy and stay on the same pattern position (dp[i + 1][j]). Otherwise the current characters must match and both move forward.

### Implementation

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        const int m = s.size();
        const int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[m][n] = true;
        for (int i = m; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                const bool first = i < m && (p[j] == s[i] || p[j] == '.');
                if (j + 1 < n && p[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || (first && dp[i + 1][j]);
                } else {
                    dp[i][j] = first && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};
```

### Complexity Analysis

* Time complexity: **O(m * n)**.
* Space complexity: **O(m * n)**.
