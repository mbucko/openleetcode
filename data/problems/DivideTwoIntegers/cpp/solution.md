### Approach

Long division in binary. Working with absolute values, try each shift from 31 down to 0: if the divisor shifted left by that amount still fits into what is left of the dividend, subtract it and set that bit of the quotient. Handle the one overflowing case (-2^31 / -1) first, then apply the sign.

### Implementation

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        const bool negative = (dividend < 0) != (divisor < 0);
        long long a = llabs(static_cast<long long>(dividend));
        const long long b = llabs(static_cast<long long>(divisor));
        long long quotient = 0;
        for (int shift = 31; shift >= 0; --shift) {
            if ((a >> shift) >= b) {
                a -= b << shift;
                quotient += 1LL << shift;
            }
        }
        return static_cast<int>(negative ? -quotient : quotient);
    }
};
```

### Complexity Analysis

* Time complexity: **O(1), at most 32 steps**.
* Space complexity: **O(1)**.
