### Approach

Sort the candidates and backtrack. At each step, try every candidate from the current position onwards. Staying at the same position lets a candidate repeat, and never going back to an earlier one prevents listing the same combination twice. Stop early once a candidate is larger than what is left. Trying candidates in ascending order gives the required ordering.

### Implementation

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
            current.push_back(candidates[i]);
            build(candidates, i, remaining - candidates[i], current, result);
            current.pop_back();
        }
    }
};
```

### Complexity Analysis

* Time complexity: **Exponential in target / min(candidates)**.
* Space complexity: **O(target / min(candidates)) recursion depth, besides the output**.
