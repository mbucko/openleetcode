### Approach

Sort the array. For each first value (skipping repeats), look for pairs in the rest of the array that cancel it out using two pointers: move the left pointer right if the sum is too small, and the right pointer left if it is too big. After a match, skip repeated values so no triplet is listed twice. Because the array is sorted, the triplets come out in the required order.

### Implementation

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i + 2 < static_cast<int>(nums.size()); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                const int total = nums[i] + nums[left] + nums[right];
                if (total < 0) {
                    ++left;
                } else if (total > 0) {
                    --right;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                    while (left < right && nums[left] == nums[left - 1]) {
                        ++left;
                    }
                    --right;
                }
            }
        }
        return result;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n^2)**.
* Space complexity: **O(log n) to O(n) for sorting**.
