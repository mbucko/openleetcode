### Approach

Take digits off the end of x one at a time and push them onto the result. Before each push, check whether result * 10 + digit would leave the 32-bit range, and return 0 if it would. This keeps every intermediate value inside 32 bits.

### Implementation

```python
class Solution:
    def reverse(self, x: int) -> int:
        INT_MAX = 2**31 - 1
        sign = -1 if x < 0 else 1
        x = abs(x)
        result = 0
        while x:
            result = result * 10 + x % 10
            x //= 10
        result *= sign
        if result < -INT_MAX - 1 or result > INT_MAX:
            return 0
        return result
```

### Complexity Analysis

* Time complexity: **O(log10 |x|)**.
* Space complexity: **O(1)**.
