### Approach

Dynamic programming: d[i][j] is the distance between the first i characters of word1 and the first j of word2. If the last characters match, d[i][j] = d[i-1][j-1]. Otherwise take 1 plus the best of replace (d[i-1][j-1]), delete (d[i-1][j]) and insert (d[i][j-1]). Only the previous row is needed at any time.

### Implementation

```cpp
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
```

### Complexity Analysis

* Time complexity: **O(m * n)**.
* Space complexity: **O(n)**.
