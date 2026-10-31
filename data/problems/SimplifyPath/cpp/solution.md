### Approach

Split the path on '/' and keep a stack of directory names. Skip empty parts (from repeated slashes) and ".". ".." pops the stack if it isn't empty. Any other part is pushed. Join the stack with single slashes after a leading '/'.

### Implementation

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string part;
        while (getline(ss, part, '/')) {
            if (part == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else if (!part.empty() && part != ".") {
                stack.push_back(part);
            }
        }
        string result;
        for (const string& name : stack) {
            result += "/" + name;
        }
        return result.empty() ? "/" : result;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(n)**.
