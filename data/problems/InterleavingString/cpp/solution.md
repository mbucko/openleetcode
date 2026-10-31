### Approach

Dynamic programming: dp[i][j] says whether the first i characters of s1 and the first j of s2 can interleave into the first i + j characters of s3. That is true if the last character came from s1 (dp[i-1][j] and s1[i-1] matches) or from s2 (dp[i][j-1] and s2[j-1] matches). Keep a single row and update it in place.

### Implementation

```cpp
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int m = s1.size();
        const int n = s2.size();
        if (m + n != static_cast<int>(s3.size())) {
            return false;
        }
        vector<bool> dp(n + 1, false);
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0 && j == 0) {
                    dp[j] = true;
                } else {
                    const bool fromS1 = i > 0 && dp[j] && s1[i - 1] == s3[i + j - 1];
                    const bool fromS2 = j > 0 && dp[j - 1] && s2[j - 1] == s3[i + j - 1];
                    dp[j] = fromS1 || fromS2;
                }
            }
        }
        return dp[n];
    }
};
```

### Complexity Analysis

* Time complexity: **O(m * n)**.
* Space complexity: **O(n)**.
