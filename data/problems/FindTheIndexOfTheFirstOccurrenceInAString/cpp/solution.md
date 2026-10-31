### Approach

Knuth-Morris-Pratt. First compute, for every prefix of needle, how long its longest proper prefix-that-is-also-a-suffix is. While scanning haystack, a mismatch then falls back to that length instead of restarting, so no character of haystack is read more than a constant number of times.

### Implementation

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        // Knuth-Morris-Pratt: fail[i] is the length of the longest proper
        // prefix of needle[0..i] that is also its suffix.
        vector<int> fail(needle.size(), 0);
        for (size_t i = 1, length = 0; i < needle.size(); ++i) {
            while (length && needle[i] != needle[length]) {
                length = fail[length - 1];
            }
            if (needle[i] == needle[length]) {
                ++length;
            }
            fail[i] = length;
        }
        for (size_t i = 0, matched = 0; i < haystack.size(); ++i) {
            while (matched && haystack[i] != needle[matched]) {
                matched = fail[matched - 1];
            }
            if (haystack[i] == needle[matched]) {
                ++matched;
            }
            if (matched == needle.size()) {
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n + m)**.
* Space complexity: **O(m)**.
