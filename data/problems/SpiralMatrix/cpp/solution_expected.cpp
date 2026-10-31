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