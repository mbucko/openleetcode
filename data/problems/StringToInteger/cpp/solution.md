### Approach

Follow the steps directly: skip spaces, read an optional sign, then build the number digit by digit. Stop as soon as the value passes the 32-bit range and return the clamped limit. That way the running value never grows without bound.

### Implementation

```cpp
class Solution {
public:
    int myAtoi(string s) {
        size_t i = 0;
        while (i < s.size() && s[i] == ' ') {
            ++i;
        }
        int sign = 1;
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = s[i] == '-' ? -1 : 1;
            ++i;
        }
        long long result = 0;
        while (i < s.size() && isdigit(static_cast<unsigned char>(s[i]))) {
            result = result * 10 + (s[i] - '0');
            if (sign * result > INT_MAX) {
                return INT_MAX;
            }
            if (sign * result < INT_MIN) {
                return INT_MIN;
            }
            ++i;
        }
        return static_cast<int>(sign * result);
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
