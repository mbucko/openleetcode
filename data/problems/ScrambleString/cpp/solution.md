### Approach

A scramble of s1 into s2 splits s1 at some position k. Either the two parts stay in order and match the first k and last n - k characters of s2, or they were swapped and match the last k and first n - k. Check both options recursively for every k. Memoising on the pair of substrings (or using a table indexed by length and start positions) keeps it polynomial, and the Python version also rejects pairs with different letters early.

### Implementation

```cpp
class Solution {
public:
    bool isScramble(string s1, string s2) {
        const int n = s1.size();
        // dp[len][i][j]: can s1.substr(i, len) be scrambled into s2.substr(j, len)?
        vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(n, vector<bool>(n, false)));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[1][i][j] = s1[i] == s2[j];
            }
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                for (int j = 0; j + len <= n; ++j) {
                    for (int k = 1; k < len && !dp[len][i][j]; ++k) {
                        dp[len][i][j] = (dp[k][i][j] && dp[len - k][i + k][j + k]) ||
                                        (dp[k][i][j + len - k] && dp[len - k][i + k][j]);
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};
```

### Complexity Analysis

* Time complexity: **O(n^4)**.
* Space complexity: **O(n^3)**.
