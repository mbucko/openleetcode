### Approach

Backtracking. Build the string one character at a time: you may add '(' while fewer than n have been used, and ')' while it would close an open one. Every complete string built this way is balanced. Trying '(' before ')' produces the strings in lexicographic order.

### Implementation

```cpp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        build(n, 0, 0, current, result);
        return result;
    }

private:
    void build(int n, int opened, int closed, string& current, vector<string>& result) {
        if (static_cast<int>(current.size()) == 2 * n) {
            result.push_back(current);
            return;
        }
        if (opened < n) {
            current.push_back('(');
            build(n, opened + 1, closed, current, result);
            current.pop_back();
        }
        if (closed < opened) {
            current.push_back(')');
            build(n, opened, closed + 1, current, result);
            current.pop_back();
        }
    }
};
```

### Complexity Analysis

* Time complexity: **O(4^n / sqrt(n)), the number of valid strings**.
* Space complexity: **O(n) recursion depth, besides the output**.
