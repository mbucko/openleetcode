### Approach

Dutch national flag partitioning with three pointers. Everything before low is 0, everything from low up to mid is 1, and everything after high is 2. Look at nums[mid]: swap a 0 down to low, leave a 1 in place, or swap a 2 up to high. After a swap with high, don't advance mid, because the value that came back hasn't been checked yet.

### Implementation

```cpp
class Solution {
public:
    vector<int> sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low++], nums[mid++]);
            } else if (nums[mid] == 1) {
                ++mid;
            } else {
                swap(nums[mid], nums[high--]);
            }
        }
        return nums;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n), one pass**.
* Space complexity: **O(1)**.
