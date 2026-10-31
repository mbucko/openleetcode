### Approach

Move two pointers inwards from both ends, skipping characters that are not letters or digits, and compare the rest case-insensitively.

### Implementation

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (!isalnum(static_cast<unsigned char>(s[left]))) {
                ++left;
            } else if (!isalnum(static_cast<unsigned char>(s[right]))) {
                --right;
            } else {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                ++left;
                --right;
            }
        }
        return true;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
