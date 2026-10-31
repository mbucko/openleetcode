### Approach

Fast exponentiation by squaring. Read n in binary. Each step squares x, and when the current bit of n is set, the current power of x is multiplied into the result. A negative exponent means using 1 / x with -n. In C++, -n is computed in 64 bits so that n = -2^31 doesn't overflow.

### Implementation

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;
        if (power < 0) {
            x = 1 / x;
            power = -power;
        }
        double result = 1.0;
        while (power) {
            if (power & 1) {
                result *= x;
            }
            x *= x;
            power >>= 1;
        }
        return result;
    }
};
```

### Complexity Analysis

* Time complexity: **O(log |n|)**.
* Space complexity: **O(1)**.
