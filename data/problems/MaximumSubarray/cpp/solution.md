### Approach

Kadane's algorithm: the best subarray ending at index i either extends the best one ending at i - 1 or starts fresh at i. Track the largest value seen.

### Implementation

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0];
        int best = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            cur = max(nums[i], cur + nums[i]);
            best = max(best, cur);
        }
        return best;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
