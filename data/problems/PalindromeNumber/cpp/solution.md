### Approach

Negative numbers and numbers ending in 0 (except 0 itself) can't be palindromes. Otherwise, reverse digits from the back until the reversed part is at least as large as what is left, then compare the two halves. For an odd digit count, drop the middle digit. Reversing only half the number also avoids overflow.

### Implementation

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }
        return x == reversedHalf || x == reversedHalf / 10;
    }
};
```

### Complexity Analysis

* Time complexity: **O(log10 x)**.
* Space complexity: **O(1)**.
