### Approach

Track both the largest and the smallest product of a subarray ending at the current index. Multiplying by a negative number swaps them. At each step the new values come from the element alone or the element times either previous extreme.

### Implementation

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = nums[0];
        int curMin = nums[0];
        int best = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            const int x = nums[i];
            const int a = curMax * x;
            const int b = curMin * x;
            curMax = max({x, a, b});
            curMin = min({x, a, b});
            best = max(best, curMax);
        }
        return best;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
