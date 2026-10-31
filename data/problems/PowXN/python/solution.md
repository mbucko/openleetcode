### Approach

Fast exponentiation by squaring. Read n in binary. Each step squares x, and when the current bit of n is set, the current power of x is multiplied into the result. A negative exponent means using 1 / x with -n. In C++, -n is computed in 64 bits so that n = -2^31 doesn't overflow.

### Implementation

```python
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            x = 1 / x
            n = -n
        result = 1.0
        while n:
            if n & 1:
                result *= x
            x *= x
            n >>= 1
        return result
```

### Complexity Analysis

* Time complexity: **O(log |n|)**.
* Space complexity: **O(1)**.
