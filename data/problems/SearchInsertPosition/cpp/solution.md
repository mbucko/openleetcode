### Approach

Binary search for the first index whose value is at least target. That is target's index if it is present, and its insertion point otherwise.

### Implementation

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            const int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
```

### Complexity Analysis

* Time complexity: **O(log n)**.
* Space complexity: **O(1)**.
