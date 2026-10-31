class Solution {
public:
    vector<int> removeElement(vector<int>& nums, int val) {
        size_t k = 0;
        for (const int num : nums) {
            if (num != val) {
                nums[k++] = num;
            }
        }
        nums.resize(k);
        return nums;
    }
};