### Approach

Sort the values and backtrack. Every partial selection is itself a subset, so record it as soon as you reach it, then try extending it with each later value. Recording before extending, and trying values in ascending order, produces the subsets in lexicographic order.

### Implementation

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
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
