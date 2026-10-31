### Approach

Add from the last digit. A 9 becomes 0 and the carry moves left. Any other digit just goes up by one and you're done. If every digit was 9, they are all 0 now, so put a 1 in front.

### Implementation

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                ++digits[i];
                return digits;
            }
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1) extra, besides a possible new leading digit**.
