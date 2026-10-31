### Approach

Sort the array, fix the first two values with nested loops (skipping repeats), and find the remaining pair with two pointers, the same way as 3Sum. Sums of four values can pass the 32-bit range, so C++ adds them as 64-bit integers.

### Implementation

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        vector<vector<int>> result;
        for (int i = 0; i + 3 < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j + 2 < n; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    const long long total = static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right];
                    if (total < target) {
                        ++left;
                    } else if (total > target) {
                        --right;
                    } else {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        ++left;
                        while (left < right && nums[left] == nums[left - 1]) {
                            ++left;
                        }
                        --right;
                    }
                }
            }
        }
        return result;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n^3)**.
* Space complexity: **O(log n) to O(n) for sorting**.
