### Approach

Scan left to right while tracking the farthest index reachable so far. If the scan ever reaches an index beyond that, the index can't be reached, and neither can anything after it.

### Implementation

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (i > farthest) {
                return false;
            }
            farthest = max(farthest, i + nums[i]);
        }
        return true;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
