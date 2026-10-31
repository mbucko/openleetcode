### Approach

Strings of different lengths can't be anagrams. Otherwise, add one per letter of s and remove one per letter of t in a 26-slot array. The strings are anagrams if every slot ends at zero.

### Implementation

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        int counts[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            ++counts[s[i] - 'a'];
            --counts[t[i] - 'a'];
        }
        for (const int count : counts) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1), the array has a fixed 26 slots**.
