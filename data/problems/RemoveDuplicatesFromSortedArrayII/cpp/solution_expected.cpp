class Solution {
public:
    vector<int> removeDuplicates(vector<int>& nums) {
        size_t k = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (k < 2 || nums[i] != nums[k - 2]) {
                nums[k++] = nums[i];
            }
        }
        nums.resize(k);
        return nums;
    }
};