class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> stack;
        int best = 0;
        const int n = heights.size();
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
        return best;
    }
};