### Approach

Binary search for the largest integer whose square is at most x. Round the midpoint up so the search always makes progress when low = mid. In C++, use 64-bit arithmetic so mid * mid can't overflow.

### Implementation

```python
class Solution:
    def mySqrt(self, x: int) -> int:
        low, high = 0, x
        while low < high:
            mid = (low + high + 1) // 2
            if mid * mid <= x:
                low = mid
            else:
                high = mid - 1
        return low
```

### Complexity Analysis

* Time complexity: **O(log x)**.
* Space complexity: **O(1)**.
