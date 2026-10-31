### Approach

Greedy matching with backtracking to the most recent '*'. Match characters and '?' directly. When you meet a '*', remember where it is and first let it match nothing. On a later mismatch, go back and let that '*' absorb one more character. Only the latest '*' ever needs revisiting, because it can stretch to cover anything an earlier one could.

### Implementation

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        size_t i = 0;
        size_t j = 0;
        int star = -1;
        size_t match = 0;
        while (i < s.size()) {
            if (j < p.size() && (p[j] == s[i] || p[j] == '?')) {
                ++i;
                ++j;
            } else if (j < p.size() && p[j] == '*') {
                star = j;
                match = i;
                ++j;
            } else if (star != -1) {
                j = star + 1;
                i = ++match;
            } else {
                return false;
            }
        }
        while (j < p.size() && p[j] == '*') {
            ++j;
        }
        return j == p.size();
    }
};
```

### Complexity Analysis

* Time complexity: **O(m * n) in the worst case, usually close to linear**.
* Space complexity: **O(1)**.
