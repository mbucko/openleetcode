### Approach

Push opening brackets onto a stack. A closing bracket must match the bracket on top of the stack, which is the most recently opened one, and that bracket is popped. The string is valid if every closing bracket matched and the stack ends empty.

### Implementation

```cpp
class Solution {
public:
    bool isValid(string s) {
        const unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
        vector<char> stack;
        for (const char ch : s) {
            const auto it = pairs.find(ch);
            if (it != pairs.end()) {
                if (stack.empty() || stack.back() != it->second) {
                    return false;
                }
                stack.pop_back();
            } else {
                stack.push_back(ch);
            }
        }
        return stack.empty();
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(n)**.
