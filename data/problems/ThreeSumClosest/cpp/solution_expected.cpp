class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int best = nums[0] + nums[1] + nums[2];
        for (int i = 0; i + 2 < static_cast<int>(nums.size()); ++i) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                const int total = nums[i] + nums[left] + nums[right];
                if (abs(total - target) < abs(best - target)) {
                    best = total;
                }
                if (total < target) {
                    ++left;
                } else if (total > target) {
                    --right;
                } else {
                    return total;
                }
            }
        }
        return best;
    }
};