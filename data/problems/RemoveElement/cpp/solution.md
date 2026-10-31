### Approach

Keep a write position k. Scan the array and copy every value that is not val to position k, then advance k. Values equal to val are skipped, so the kept values stay in their original order.

### Implementation

```cpp
class Solution {
public:
    vector<int> removeElement(vector<int>& nums, int val) {
        size_t k = 0;
        for (const int num : nums) {
            if (num != val) {
                nums[k++] = num;
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
