class Solution {
public:
    vector<int> sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low++], nums[mid++]);
            } else if (nums[mid] == 1) {
                ++mid;
            } else {
                swap(nums[mid], nums[high--]);
            }
        }
        return nums;
    }
};