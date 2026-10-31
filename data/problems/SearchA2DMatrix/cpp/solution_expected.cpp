class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int n = matrix[0].size();
        int low = 0;
        int high = matrix.size() * n - 1;
        while (low <= high) {
            const int mid = low + (high - low) / 2;
            const int value = matrix[mid / n][mid % n];
            if (value == target) {
                return true;
            }
            if (value < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};