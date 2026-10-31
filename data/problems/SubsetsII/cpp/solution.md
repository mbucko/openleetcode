### Approach

Sort the values and backtrack as for Subsets, recording every partial selection. To avoid repeats, skip a value at a given depth if it equals the value tried just before it at the same depth. The first copy already led to every subset that copy could start.

### Implementation

```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> current;
        build(nums, 0, current, result);
        return result;
    }

private:
    void build(const vector<int>& nums, size_t start, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);
        for (size_t i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            current.push_back(nums[i]);
            build(nums, i + 1, current, result);
            current.pop_back();
        }
    }
};
```

### Complexity Analysis

* Time complexity: **O(n * 2^n)**.
* Space complexity: **O(n) recursion depth, besides the output**.
