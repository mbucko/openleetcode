### Approach

Count instead of generating. With r digits left, each choice of first digit starts a block of (r - 1)! orderings. Dividing the zero-based k by (r - 1)! tells you which unused digit comes next, and the remainder is the position within that block. Repeat for each position.

### Implementation

```python
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        digits = [str(d) for d in range(1, n + 1)]
        factorial = [1] * (n + 1)
        for i in range(1, n + 1):
            factorial[i] = factorial[i - 1] * i
        k -= 1
        result = []
        for remaining in range(n, 0, -1):
            index, k = divmod(k, factorial[remaining - 1])
            result.append(digits.pop(index))
        return "".join(result)
```

### Complexity Analysis

* Time complexity: **O(n^2)**.
* Space complexity: **O(n)**.
