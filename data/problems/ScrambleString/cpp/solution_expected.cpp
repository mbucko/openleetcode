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