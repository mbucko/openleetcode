### Approach

Place one queen per row with backtracking. Track the used columns and both kinds of diagonal: row - col is constant along one direction and row + col along the other, so each check takes constant time. Trying columns left to right gives the required ordering.

### Implementation

```cpp
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false);
        vector<bool> diag(2 * n, false);
        vector<bool> anti(2 * n, false);
        place(0, n, board, cols, diag, anti, result);
        return result;
    }

private:
    void place(int row, int n, vector<string>& board, vector<bool>& cols, vector<bool>& diag,
               vector<bool>& anti, vector<vector<string>>& result) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (cols[col] || diag[row - col + n] || anti[row + col]) {
                continue;
            }
            board[row][col] = 'Q';
            cols[col] = diag[row - col + n] = anti[row + col] = true;
            place(row + 1, n, board, cols, diag, anti, result);
            board[row][col] = '.';
            cols[col] = diag[row - col + n] = anti[row + col] = false;
        }
    }
};
```

### Complexity Analysis

* Time complexity: **O(n!)**.
* Space complexity: **O(n) besides the output**.
