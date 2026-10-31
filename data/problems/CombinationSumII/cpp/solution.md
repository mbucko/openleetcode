### Approach

Sort the candidates and backtrack, moving past each candidate once it is used. To avoid repeated combinations, skip a value at a given depth if the same value was already tried at that depth (i > start and it equals the previous value). The first copy already covers every combination that uses it.

### Implementation

```cpp
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
```

### Complexity Analysis

* Time complexity: **O(2^n) in the worst case**.
* Space complexity: **O(n) recursion depth, besides the output**.
