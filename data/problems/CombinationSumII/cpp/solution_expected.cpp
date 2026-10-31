class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        build(candidates, 0, target, current, result);
        return result;
    }

private:
    void build(const vector<int>& candidates, size_t start, int remaining,
               vector<int>& current, vector<vector<int>>& result) {
        if (remaining == 0) {
            result.push_back(current);
            return;
        }
        for (size_t i = start; i < candidates.size() && candidates[i] <= remaining; ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            current.push_back(candidates[i]);
            build(candidates, i + 1, remaining - candidates[i], current, result);
            current.pop_back();
        }
    }
};