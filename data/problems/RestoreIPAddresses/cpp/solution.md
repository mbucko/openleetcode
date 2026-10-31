### Approach

Backtracking over where the dots go. Take the next number as 1, 2 or 3 digits, as long as it has no leading zero and is at most 255, and recurse. A candidate is complete when there are exactly four numbers and every digit has been used. Sort the addresses at the end.

### Implementation

```cpp
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> parts;
        build(s, 0, parts, result);
        sort(result.begin(), result.end());
        return result;
    }

private:
    void build(const string& s, size_t start, vector<string>& parts, vector<string>& result) {
        if (parts.size() == 4) {
            if (start == s.size()) {
                result.push_back(parts[0] + "." + parts[1] + "." + parts[2] + "." + parts[3]);
            }
            return;
        }
        for (size_t length = 1; length <= 3 && start + length <= s.size(); ++length) {
            const string piece = s.substr(start, length);
            if ((piece[0] == '0' && length > 1) || stoi(piece) > 255) {
                break;
            }
            parts.push_back(piece);
            build(s, start + length, parts, result);
            parts.pop_back();
        }
    }
};
```

### Complexity Analysis

* Time complexity: **O(1), at most 3^4 ways to split**.
* Space complexity: **O(1) besides the output**.
