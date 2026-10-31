class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i + 2 < static_cast<int>(nums.size()); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                const int total = nums[i] + nums[left] + nums[right];
                if (total < 0) {
                    ++left;
                } else if (total > 0) {
                    --right;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                    while (left < right && nums[left] == nums[left - 1]) {
                        ++left;
                    }
                    --right;
                }
            }
        }
        return result;
    }
};