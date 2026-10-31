### Approach

Scan the board once and record, for every filled cell, that its digit has been used in its row, its column and its box. If any of those three was already recorded, the board breaks a rule.

### Implementation

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {};
        bool cols[9][9] = {};
        bool boxes[9][9] = {};
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }
                const int d = board[r][c] - '1';
                const int b = (r / 3) * 3 + c / 3;
                if (rows[r][d] || cols[c][d] || boxes[b][d]) {
                    return false;
                }
                rows[r][d] = cols[c][d] = boxes[b][d] = true;
            }
        }
        return true;
    }
};
```

### Complexity Analysis

* Time complexity: **O(1), the board is always 9 x 9**.
* Space complexity: **O(1)**.
