class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int n = grid[0].size();
        vector<int> row(n, INT_MAX);
        row[0] = 0;
        for (const auto& gridRow : grid) {
            row[0] += gridRow[0];
            for (int c = 1; c < n; ++c) {
                row[c] = min(row[c], row[c - 1]) + gridRow[c];
            }
        }
        return row[n - 1];
    }
};