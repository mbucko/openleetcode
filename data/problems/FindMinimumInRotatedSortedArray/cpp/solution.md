### Approach

Binary search, comparing the middle element with the rightmost one. If the middle is larger, the rotation point (the minimum) is to its right. Otherwise the minimum is at the middle or to its left.

### Implementation

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            const int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};
```

### Complexity Analysis

* Time complexity: **O(log n)**.
* Space complexity: **O(1)**.
