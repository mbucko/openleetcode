### Approach

Add the strings from the right, the way you add on paper. Each position adds two bits and the carry, writes the sum modulo 2, and carries the rest. The digits come out least significant first, so reverse them at the end.

### Implementation

```python
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        result = []
        i, j = len(a) - 1, len(b) - 1
        carry = 0
        while i >= 0 or j >= 0 or carry:
            total = carry
            if i >= 0:
                total += ord(a[i]) - 48
                i -= 1
            if j >= 0:
                total += ord(b[j]) - 48
                j -= 1
            result.append(str(total % 2))
            carry = total // 2
        return "".join(reversed(result))
```

### Complexity Analysis

* Time complexity: **O(max(m, n))**.
* Space complexity: **O(max(m, n)) for the output**.
