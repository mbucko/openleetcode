class Solution {
public:
    int minDistance(string word1, string word2) {
        const int m = word1.size();
        const int n = word2.size();
        vector<int> prev(n + 1);
        for (int j = 0; j <= n; ++j) {
            prev[j] = j;
        }
        for (int i = 1; i <= m; ++i) {
            vector<int> cur(n + 1);
            cur[0] = i;
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    cur[j] = prev[j - 1];
                } else {
                    cur[j] = 1 + min({prev[j - 1], prev[j], cur[j - 1]});
                }
            }
            prev = move(cur);
        }
        return prev[n];
    }
};