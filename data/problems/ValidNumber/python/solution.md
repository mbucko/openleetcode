### Approach

Scan once, tracking whether a digit, a decimal point and an exponent have been seen. A sign is only allowed at the start or right after the exponent letter. The exponent letter needs a digit before it and may appear once, and it resets the digit flag because the exponent needs its own digits. A decimal point may appear once, and only before the exponent. The string is valid if it ends having seen a digit in the current part.

### Implementation

```python
class Solution:
    def isNumber(self, s: str) -> bool:
        seen_digit = seen_dot = seen_exp = False
        for i, ch in enumerate(s):
            if ch.isdigit():
                seen_digit = True
            elif ch in "+-":
                if i > 0 and s[i - 1] not in "eE":
                    return False
            elif ch in "eE":
                if seen_exp or not seen_digit:
                    return False
                seen_exp = True
                seen_digit = False
            elif ch == ".":
                if seen_dot or seen_exp:
                    return False
                seen_dot = True
            else:
                return False
        return seen_digit
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
