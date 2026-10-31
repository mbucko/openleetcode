### Approach

Peel the matrix one ring at a time, keeping four boundaries: top, bottom, left and right. Walk the top row, the right column, then the bottom row backwards and the left column upwards, and shrink all four boundaries. When only a single row or column is left, the last two walks are skipped so nothing is visited twice.

### Implementation

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        while (top <= bottom && left <= right) {
            for (int c = left; c <= right; ++c) {
                result.push_back(matrix[top][c]);
            }
            for (int r = top + 1; r <= bottom; ++r) {
                result.push_back(matrix[r][right]);
            }
            if (top < bottom && left < right) {
                for (int c = right - 1; c >= left; --c) {
                    result.push_back(matrix[bottom][c]);
                }
                for (int r = bottom - 1; r > top; --r) {
                    result.push_back(matrix[r][left]);
                }
            }
            ++top;
            --bottom;
            ++left;
            --right;
        }
        return result;
    }
};
```

### Complexity Analysis

* Time complexity: **O(m * n)**.
* Space complexity: **O(1) extra, besides the output**.
