class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        build(nums, used, current, result);
        return result;
    }

private:
    void build(const vector<int>& nums, vector<bool>& used, vector<int>& current,
               vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            used[i] = true;
            current.push_back(nums[i]);
            build(nums, used, current, result);
            current.pop_back();
            used[i] = false;
        }
    }
};