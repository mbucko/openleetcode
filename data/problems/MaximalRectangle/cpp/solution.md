### Approach

Treat each row as the floor of a histogram, where a column's bar height is the number of consecutive 1s ending at that row. Each row's histogram is updated from the previous one in O(n). Then find its largest rectangle with the monotonic-stack method from Largest Rectangle in Histogram, and keep the best over all rows.

### Implementation

```cpp
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        const int n = matrix[0].size();
        vector<int> heights(n, 0);
        int best = 0;
        for (const auto& row : matrix) {
            for (int c = 0; c < n; ++c) {
                heights[c] = row[c] == '1' ? heights[c] + 1 : 0;
            }
            vector<pair<int, int>> stack;
            for (int i = 0; i <= n; ++i) {
                const int h = i < n ? heights[i] : 0;
                int start = i;
                while (!stack.empty() && stack.back().second >= h) {
                    const auto [index, height] = stack.back();
                    stack.pop_back();
                    best = max(best, height * (i - index));
                    start = index;
                }
                stack.push_back({start, h});
            }
        }
        return best;
    }
};
```

### Complexity Analysis

* Time complexity: **O(m * n)**.
* Space complexity: **O(n)**.
