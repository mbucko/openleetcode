### Approach

Build the combinations one digit at a time. Start with a single empty string, and for each digit extend every string so far with each of that digit's letters. The keypad letters are in alphabetical order and earlier digits vary slowest, so the result comes out in lexicographic order.

### Implementation

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        const vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result = {""};
        for (const char digit : digits) {
            vector<string> next;
            for (const string& prefix : result) {
                for (const char letter : keypad[digit - '0']) {
                    next.push_back(prefix + letter);
                }
            }
            result = move(next);
        }
        return result;
    }
};
```

### Complexity Analysis

* Time complexity: **O(4^n * n)**.
* Space complexity: **O(4^n * n) for the output**.
