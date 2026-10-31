### Approach

Sliding window. Count how many of each character t still needs, plus the total still missing. Grow the window to the right, and each character that was still needed lowers the missing count. When nothing is missing, the window is valid: record it, then shrink from the left until removing a character makes it invalid again.

### Implementation

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        int need[128] = {0};
        for (const char ch : t) {
            ++need[static_cast<unsigned char>(ch)];
        }
        int missing = t.size();
        int bestStart = 0;
        int bestLen = INT_MAX;
        int left = 0;
        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            if (need[static_cast<unsigned char>(s[right])]-- > 0) {
                --missing;
            }
            while (missing == 0) {
                if (right - left + 1 < bestLen) {
                    bestStart = left;
                    bestLen = right - left + 1;
                }
                if (++need[static_cast<unsigned char>(s[left])] > 0) {
                    ++missing;
                }
                ++left;
            }
        }
        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};
```

### Complexity Analysis

* Time complexity: **O(m + n)**.
* Space complexity: **O(1), the alphabet is fixed**.
