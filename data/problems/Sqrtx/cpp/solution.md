### Approach

Binary search for the largest integer whose square is at most x. Round the midpoint up so the search always makes progress when low = mid. In C++, use 64-bit arithmetic so mid * mid can't overflow.

### Implementation

```cpp
class Solution {
public:
    int mySqrt(int x) {
        long long low = 0;
        long long high = x;
        while (low < high) {
            const long long mid = (low + high + 1) / 2;
            if (mid * mid <= x) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return static_cast<int>(low);
    }
};
```

### Complexity Analysis

* Time complexity: **O(log x)**.
* Space complexity: **O(1)**.
