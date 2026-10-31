### Approach

Take digits off the end of x one at a time and push them onto the result. Before each push, check whether result * 10 + digit would leave the 32-bit range, and return 0 if it would. This keeps every intermediate value inside 32 bits.

### Implementation

```cpp
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x != 0) {
            const int digit = x % 10;
            x /= 10;
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return 0;
            }
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8)) {
                return 0;
            }
            result = result * 10 + digit;
        }
        return result;
    }
};
```

### Complexity Analysis

* Time complexity: **O(log10 |x|)**.
* Space complexity: **O(1)**.
