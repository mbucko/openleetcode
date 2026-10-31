### Approach

Sort the array. For each first value, scan the rest with two pointers. A sum that is too small moves the left pointer right, and one that is too large moves the right pointer left. Keep the sum closest to the target, and stop early on an exact hit.

### Implementation

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int best = nums[0] + nums[1] + nums[2];
        for (int i = 0; i + 2 < static_cast<int>(nums.size()); ++i) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                const int total = nums[i] + nums[left] + nums[right];
                if (abs(total - target) < abs(best - target)) {
                    best = total;
                }
                if (total < target) {
                    ++left;
                } else if (total > target) {
                    --right;
                } else {
                    return total;
                }
            }
        }
        return best;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n^2)**.
* Space complexity: **O(log n) to O(n) for sorting**.
