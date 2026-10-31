### Approach

Scan once, tracking whether a digit, a decimal point and an exponent have been seen. A sign is only allowed at the start or right after the exponent letter. The exponent letter needs a digit before it and may appear once, and it resets the digit flag because the exponent needs its own digits. A decimal point may appear once, and only before the exponent. The string is valid if it ends having seen a digit in the current part.

### Implementation

```cpp
class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenExp = false;
        for (size_t i = 0; i < s.size(); ++i) {
            const char ch = s[i];
            if (isdigit(static_cast<unsigned char>(ch))) {
                seenDigit = true;
            } else if (ch == '+' || ch == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } else if (ch == 'e' || ch == 'E') {
                if (seenExp || !seenDigit) {
                    return false;
                }
                seenExp = true;
                seenDigit = false;
            } else if (ch == '.') {
                if (seenDot || seenExp) {
                    return false;
                }
                seenDot = true;
            } else {
                return false;
            }
        }
        return seenDigit;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
