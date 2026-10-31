### Approach

From the right, find the first position i where nums[i] < nums[i + 1]. Everything after i is in descending order, the last arrangement of that suffix. Swap nums[i] with the smallest value to its right that is larger than it, then reverse the suffix so it becomes ascending, its first arrangement. If no such i exists, the whole array is descending, and reversing it gives the first permutation.

### Implementation

```cpp
class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (nums[j] <= nums[i]) {
                --j;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
        return nums;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
