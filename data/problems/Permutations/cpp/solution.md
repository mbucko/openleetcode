### Approach

Sort the values, then backtrack: at each position, try every value not yet used, recurse, then undo. Trying values in ascending order at every position produces the permutations in lexicographic order.

### Implementation

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
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
            if (!used[i]) {
                used[i] = true;
                current.push_back(nums[i]);
                build(nums, used, current, result);
                current.pop_back();
                used[i] = false;
            }
        }
    }
};
```

### Complexity Analysis

* Time complexity: **O(n * n!)**.
* Space complexity: **O(n) recursion depth, besides the output**.
