class Solution {
public:
    vector<int> removeDuplicates(vector<int>& nums) {
        size_t k = 1;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[k - 1]) {
                nums[k++] = nums[i];
            }
        }
        nums.resize(k);
        return nums;
    }
};