### Approach

Every palindrome is centred on a character (odd length) or between two characters (even length). Expand outwards from each of the 2n - 1 centres while both ends match, and keep the longest result.

### Implementation

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int bestStart = 0;
        int bestLen = 0;
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                --left;
                ++right;
            }
            if (right - left - 1 > bestLen) {
                bestStart = left + 1;
                bestLen = right - left - 1;
            }
        };
        for (int i = 0; i < s.size(); ++i) {
            expand(i, i);
            expand(i, i + 1);
        }
        return s.substr(bestStart, bestLen);
    }
};
```

### Complexity Analysis

* Time complexity: **O(n^2)**.
* Space complexity: **O(1)**.
