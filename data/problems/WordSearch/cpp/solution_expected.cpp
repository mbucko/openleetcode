class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int r = 0; r < static_cast<int>(board.size()); ++r) {
            for (int c = 0; c < static_cast<int>(board[0].size()); ++c) {
                if (search(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool search(vector<vector<char>>& board, const string& word, int r, int c, size_t k) {
        if (k == word.size()) {
            return true;
        }
        if (r < 0 || r >= static_cast<int>(board.size()) || c < 0 || c >= static_cast<int>(board[0].size()) ||
            board[r][c] != word[k]) {
            return false;
        }
        board[r][c] = '#';
        const bool found = search(board, word, r + 1, c, k + 1) || search(board, word, r - 1, c, k + 1) ||
                           search(board, word, r, c + 1, k + 1) || search(board, word, r, c - 1, k + 1);
        board[r][c] = word[k];
        return found;
    }
};