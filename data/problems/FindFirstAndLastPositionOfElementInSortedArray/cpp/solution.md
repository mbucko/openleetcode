### Approach

Two binary searches. The first finds the leftmost position whose value is at least target. If that value isn't target, it doesn't appear. Otherwise a second search finds the first position past target (the leftmost value greater than it), and the last occurrence sits just before that.

### Implementation

```cpp
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
```

### Complexity Analysis

* Time complexity: **O(log n)**.
* Space complexity: **O(1)**.
