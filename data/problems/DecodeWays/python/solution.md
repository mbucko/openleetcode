### Approach

Dynamic programming over prefixes. The number of decodings of the first i characters adds the decodings of the first i - 1, if the last digit alone is a letter (it isn't '0'), and of the first i - 2, if the last two digits form 10 to 26. Only the last two counts are needed.

### Implementation

```python
class Solution:
    def numDecodings(self, s: str) -> int:
        prev, cur = 1, 1 if s[0] != "0" else 0
        for i in range(1, len(s)):
            nxt = 0
            if s[i] != "0":
                nxt += cur
            if s[i - 1] == "1" or (s[i - 1] == "2" and s[i] <= "6"):
                nxt += prev
            prev, cur = cur, nxt
        return cur
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
