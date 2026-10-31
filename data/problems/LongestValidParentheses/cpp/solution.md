### Approach

Keep a stack of indices. Its bottom always holds the position just before the current balanced run, starting at -1. Push the index of each '('. A ')' pops one entry. If the stack becomes empty, this ')' is unmatched, so it becomes the new base. Otherwise the balanced run ending here started right after the index now on top.

### Implementation

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stack = {-1};
        int best = 0;
        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            if (s[i] == '(') {
                stack.push_back(i);
            } else {
                stack.pop_back();
                if (stack.empty()) {
                    stack.push_back(i);
                } else {
                    best = max(best, i - stack.back());
                }
            }
        }
        return best;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(n)**.
