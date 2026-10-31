### Approach

Start with the first string as the candidate prefix. For each other string, shorten the candidate until that string starts with it. Whatever is left at the end is common to all of them.

### Implementation

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for (size_t i = 1; i < strs.size(); ++i) {
            size_t len = 0;
            while (len < prefix.size() && len < strs[i].size() && prefix[len] == strs[i][len]) {
                ++len;
            }
            prefix.resize(len);
        }
        return prefix;
    }
};
```

### Complexity Analysis

* Time complexity: **O(S), where S is the total number of characters**.
* Space complexity: **O(1) extra, besides the result**.
