class Solution {
public:
    int totalNQueens(int n) {
        return count(0, n, 0, 0, 0);
    }

private:
    int count(int row, int n, unsigned cols, unsigned diag, unsigned anti) {
        if (row == n) {
            return 1;
        }
        int total = 0;
        for (int col = 0; col < n; ++col) {
            const unsigned c = 1u << col;
            const unsigned d = 1u << (row - col + n);
            const unsigned a = 1u << (row + col);
            if ((cols & c) || (diag & d) || (anti & a)) {
                continue;
            }
            total += count(row + 1, n, cols | c, diag | d, anti | a);
        }
        return total;
    }
};