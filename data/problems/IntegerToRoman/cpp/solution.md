### Approach

List the 13 values that have their own symbol or symbol pair, including the subtractive ones like 900 = CM, from largest to smallest. Greedily take the largest value that still fits, append its symbol, and subtract it until nothing is left.

### Implementation

```cpp
class Solution {
public:
    string intToRoman(int num) {
        const vector<pair<int, string>> values = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"},
            {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        string result;
        for (const auto& [value, symbol] : values) {
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }
        return result;
    }
};
```

### Complexity Analysis

* Time complexity: **O(1), the input is at most 3999**.
* Space complexity: **O(1)**.
