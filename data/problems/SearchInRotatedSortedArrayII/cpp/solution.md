### Approach

The same binary search as without duplicates: find the sorted half and check whether the target falls in its range. The one new case is when the left, middle and right values are all equal. Then you can't tell which half is sorted, so drop both ends and continue. That case is what makes the worst case linear.

### Implementation

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                ++left;
                --right;
            } else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};
```

### Complexity Analysis

* Time complexity: **O(log n) on average, O(n) in the worst case**.
* Space complexity: **O(1)**.
