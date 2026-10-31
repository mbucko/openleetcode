### Approach

The answer is at most n + 1, so only the values 1 to n matter. Use the array itself as a lookup table: keep swapping each value v in that range into position v - 1. Each swap puts one value into its final place, so this takes O(n) in total. Afterwards, the first position i that doesn't hold i + 1 gives the answer. If every position matches, the answer is n + 1.

### Implementation

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
