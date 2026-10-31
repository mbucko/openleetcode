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