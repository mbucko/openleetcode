### Approach

Keep a write position k that marks the end of the distinct prefix. Scan the array, and whenever a value differs from the last value written, copy it to position k and advance k. The array is sorted, so equal values are always next to each other.

### Implementation

```cpp
class Solution {
public:
    vector<int> removeDuplicates(vector<int>& nums) {
        size_t k = 1;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[k - 1]) {
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
