### Approach

Treat it as a breadth-first search over ranges. The indices reachable with k jumps form a contiguous range. While scanning that range, track the farthest index reachable from it, which is where the range for k + 1 jumps ends. Every time you pass the end of the current range, you have used one more jump.

### Implementation

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;
        for (int i = 0; i + 1 < static_cast<int>(nums.size()); ++i) {
            farthest = max(farthest, i + nums[i]);
            if (i == currentEnd) {
                ++jumps;
                currentEnd = farthest;
            }
        }
        return jumps;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
