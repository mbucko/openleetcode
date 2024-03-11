class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> visited;
        
        for (int i = 0; i < nums.size(); ++i) {
            const int curElement = nums[i];
            const int delta = target - curElement;
            
            const auto it = visited.find(delta);
            if (it != visited.end()) {
                return {it->second, i};
            }
            
            visited.insert({curElement, i});
            continue;

        }
        return {};
    }
};