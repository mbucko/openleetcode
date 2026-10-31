### Approach

The same backtracking as listing the placements, but only counting them. Place one queen per row and track the used columns and both diagonals (row - col and row + col). The C++ version keeps them as bit masks.

### Implementation

```cpp
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
```

### Complexity Analysis

* Time complexity: **O(n!)**.
* Space complexity: **O(n) recursion depth**.
