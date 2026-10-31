### Approach

Long division in binary. Working with absolute values, try each shift from 31 down to 0: if the divisor shifted left by that amount still fits into what is left of the dividend, subtract it and set that bit of the quotient. Handle the one overflowing case (-2^31 / -1) first, then apply the sign.

### Implementation

```python
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        INT_MAX = 2**31 - 1
        if dividend == -2**31 and divisor == -1:
            return INT_MAX
        negative = (dividend < 0) != (divisor < 0)
        a, b = abs(dividend), abs(divisor)
        quotient = 0
        for shift in range(31, -1, -1):
            if (a >> shift) >= b:
                a -= b << shift
                quotient += 1 << shift
        return -quotient if negative else quotient
```

### Complexity Analysis

* Time complexity: **O(1), at most 32 steps**.
* Space complexity: **O(1)**.
