### Approach

Walk both lists together from the least significant digit, the way you add numbers on paper. Each position adds the two digits and the carry, keeps the last digit of that sum and carries the rest. Keep going while either list has digits left or a carry remains.

### Implementation

```cpp
class Solution {
public:
    vector<int> addTwoNumbers(vector<int>& l1, vector<int>& l2) {
        vector<int> result;
        int carry = 0;
        for (size_t i = 0; i < l1.size() || i < l2.size() || carry; ++i) {
            int total = carry;
            if (i < l1.size()) {
                total += l1[i];
            }
            if (i < l2.size()) {
                total += l2[i];
            }
            result.push_back(total % 10);
            carry = total / 10;
        }
        return result;
    }
};
```

### Complexity Analysis

* Time complexity: **O(max(m, n))**.
* Space complexity: **O(1) extra, besides the output**.
