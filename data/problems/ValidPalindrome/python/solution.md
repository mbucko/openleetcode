### Approach

Use two pointers, one starting at the beginning of the string and one at the end. Move each pointer past any characters that aren't letters or numbers. Then compare the two characters in lowercase. If they don't match, the string isn't a palindrome. If they match, move both pointers toward the middle and repeat. If the pointers meet without finding a mismatch, the string is a palindrome. This avoids building a new cleaned-up string.

### Implementation

```python
class Solution:
    def isPalindrome(self, s: str) -> bool:
        left, right = 0, len(s) - 1

        while left < right:
            while left < right and not s[left].isalnum():
                left += 1
            while left < right and not s[right].isalnum():
                right -= 1

            if s[left].lower() != s[right].lower():
                return False

            left += 1
            right -= 1

        return True
```

### Complexity Analysis

* Time complexity: **O(n)**.<br>
Each character in **s** is visited at most once by one of the two pointers.

* Space complexity: **O(1)**.<br>
Only two pointer variables are used, and no new string is created.
