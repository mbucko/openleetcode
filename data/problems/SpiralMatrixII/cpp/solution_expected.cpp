class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        const int dr[] = {0, 1, 0, -1};
        const int dc[] = {1, 0, -1, 0};
        int r = 0;
        int c = 0;
        int d = 0;
        for (int value = 1; value <= n * n; ++value) {
            matrix[r][c] = value;
            const int nr = r + dr[d];
            const int nc = c + dc[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || matrix[nr][nc] != 0) {
                d = (d + 1) % 4;
            }
            r += dr[d];
            c += dc[d];
        }
        return matrix;
    }
};