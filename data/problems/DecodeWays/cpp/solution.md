### Approach

Dynamic programming over prefixes. The number of decodings of the first i characters adds the decodings of the first i - 1, if the last digit alone is a letter (it isn't '0'), and of the first i - 2, if the last two digits form 10 to 26. Only the last two counts are needed.

### Implementation

```cpp
class Solution {
public:
    int numDecodings(string s) {
        long long prev = 1;
        long long cur = s[0] != '0' ? 1 : 0;
        for (size_t i = 1; i < s.size(); ++i) {
            long long next = 0;
            if (s[i] != '0') {
                next += cur;
            }
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                next += prev;
            }
            prev = cur;
            cur = next;
        }
        return static_cast<int>(cur);
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
