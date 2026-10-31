class Solution {
public:
    vector<vector<char>> solveSudoku(vector<vector<char>>& board) {
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    empty_.push_back({r, c});
                } else {
                    place(r, c, board[r][c] - '1', true);
                }
            }
        }
        solve(board, 0);
        return board;
    }

private:
    bool rows_[9][9] = {};
    bool cols_[9][9] = {};
    bool boxes_[9][9] = {};
    vector<pair<int, int>> empty_;

    void place(int r, int c, int d, bool used) {
        rows_[r][d] = cols_[c][d] = boxes_[(r / 3) * 3 + c / 3][d] = used;
    }

    bool solve(vector<vector<char>>& board, size_t k) {
        if (k == empty_.size()) {
            return true;
        }
        const auto [r, c] = empty_[k];
        for (int d = 0; d < 9; ++d) {
            if (rows_[r][d] || cols_[c][d] || boxes_[(r / 3) * 3 + c / 3][d]) {
                continue;
            }
            board[r][c] = '1' + d;
            place(r, c, d, true);
            if (solve(board, k + 1)) {
                return true;
            }
            place(r, c, d, false);
        }
        board[r][c] = '.';
        return false;
    }
};