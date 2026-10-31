### Approach

The last move onto step i comes from step i - 1 or step i - 2, so ways(i) = ways(i - 1) + ways(i - 2), which is the Fibonacci recurrence. Keep only the last two values.

### Implementation

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int prev = 1;
        int cur = 1;
        for (int i = 2; i <= n; ++i) {
            const int next = prev + cur;
            prev = cur;
            cur = next;
        }
        return cur;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
