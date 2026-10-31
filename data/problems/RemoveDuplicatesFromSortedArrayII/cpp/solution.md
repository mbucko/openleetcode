### Approach

Keep a write position k. A value may be written if fewer than two values have been kept so far, or if it differs from the value kept two places back. Since the array is sorted, being equal to that value would mean it is a third copy.

### Implementation

```cpp
class Solution {
public:
    vector<int> removeDuplicates(vector<int>& nums) {
        size_t k = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (k < 2 || nums[i] != nums[k - 2]) {
                nums[k++] = nums[i];
            }
        }
        nums.resize(k);
        return nums;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
