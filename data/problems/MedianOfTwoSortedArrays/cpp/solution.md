### Approach

Binary search for a split of the shorter array. Taking i values from it and half - i from the other array puts exactly half of all values on the left. The split is correct when every value on the left is no larger than every value on the right. The median then comes from the largest left value, and for an even total also the smallest right value.

### Implementation

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& a = nums1.size() <= nums2.size() ? nums1 : nums2;
        vector<int>& b = nums1.size() <= nums2.size() ? nums2 : nums1;
        const int m = a.size();
        const int n = b.size();
        const int half = (m + n + 1) / 2;
        int low = 0;
        int high = m;
        while (true) {
            const int i = (low + high) / 2;
            const int j = half - i;
            const long long aLeft = i > 0 ? a[i - 1] : LLONG_MIN;
            const long long aRight = i < m ? a[i] : LLONG_MAX;
            const long long bLeft = j > 0 ? b[j - 1] : LLONG_MIN;
            const long long bRight = j < n ? b[j] : LLONG_MAX;
            if (aLeft <= bRight && bLeft <= aRight) {
                if ((m + n) % 2) {
                    return max(aLeft, bLeft);
                }
                return (max(aLeft, bLeft) + min(aRight, bRight)) / 2.0;
            }
            if (aLeft > bRight) {
                high = i - 1;
            } else {
                low = i + 1;
            }
        }
    }
};
```

### Complexity Analysis

* Time complexity: **O(log(min(m, n)))**.
* Space complexity: **O(1)**.
