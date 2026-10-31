
### Approach

Treat every position (and every gap between two adjacent characters) as the center of a palindrome and expand outward while the characters on both sides match. Track the start index and length of the longest palindrome found. When two palindromes have the same length, the earlier one is kept.

### Implementation

```python
class Solution:
    def longestPalindrome(self, s: str) -> str:
        start = 0
        best_len = 1

        def expand(left: int, right: int) -> None:
            nonlocal start, best_len
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            length = right - left - 1
            if length > best_len:
                best_len = length
                start = left + 1

        for center in range(len(s)):
            expand(center, center)
            expand(center, center + 1)

        return s[start:start + best_len]
```

### Complexity Analysis

* Time complexity: **O(n^2)**.
* Space complexity: **O(1)**.
