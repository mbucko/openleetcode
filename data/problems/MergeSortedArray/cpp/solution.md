### Approach

Fill nums1 from the back. Compare the largest remaining values of the two arrays and write the larger one into the last unfilled slot. Writing from the back never overwrites a value of nums1 that hasn't been read yet. When nums2 runs out, the rest of nums1 is already in place.

### Implementation

```cpp
class Solution {
public:
    vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        return nums1;
    }
};
```

### Complexity Analysis

* Time complexity: **O(m + n)**.
* Space complexity: **O(1)**.
