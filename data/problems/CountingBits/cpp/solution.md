### Approach

Shifting i right by one drops its lowest bit, so i has as many set bits as i >> 1 plus that lowest bit (i & 1). Fill the array from 0 upwards.

### Implementation

```cpp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1) extra, besides the output array**.
