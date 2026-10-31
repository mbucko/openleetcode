class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const auto first = lower_bound(nums.begin(), nums.end(), target);
        if (first == nums.end() || *first != target) {
            return {-1, -1};
        }
        const auto last = upper_bound(nums.begin(), nums.end(), target);
        return {static_cast<int>(first - nums.begin()), static_cast<int>(last - nums.begin()) - 1};
    }
};