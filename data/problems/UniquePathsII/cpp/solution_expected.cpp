class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        const int n = obstacleGrid[0].size();
        vector<long long> row(n, 0);
        row[0] = 1;
        for (const auto& gridRow : obstacleGrid) {
            for (int c = 0; c < n; ++c) {
                if (gridRow[c] == 1) {
                    row[c] = 0;
                } else if (c > 0) {
                    row[c] += row[c - 1];
                }
            }
        }
        return static_cast<int>(row[n - 1]);
    }
};