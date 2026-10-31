### Approach

Grade-school multiplication. The product of digit i of num1 and digit j of num2 lands at position i + j + 1 of the result, and any carry goes to position i + j. Accumulate every digit pair into a result array of length m + n, then drop leading zeros.

### Implementation

```python
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        digits = [0] * (len(num1) + len(num2))
        for i in range(len(num1) - 1, -1, -1):
            for j in range(len(num2) - 1, -1, -1):
                total = digits[i + j + 1] + (ord(num1[i]) - 48) * (ord(num2[j]) - 48)
                digits[i + j + 1] = total % 10
                digits[i + j] += total // 10
        result = "".join(map(str, digits)).lstrip("0")
        return result or "0"
```

### Complexity Analysis

* Time complexity: **O(m * n)**.
* Space complexity: **O(m + n)**.
