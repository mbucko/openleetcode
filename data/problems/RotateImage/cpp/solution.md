### Approach

A clockwise rotation is a transpose (flip across the main diagonal) followed by reversing each row. Both steps only swap elements, so they need no extra matrix.

### Implementation

```cpp
class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (auto& row : matrix) {
            reverse(row.begin(), row.end());
        }
        return matrix;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n^2)**.
* Space complexity: **O(1)**.
