### Approach

Add the strings from the right, the way you add on paper. Each position adds two bits and the carry, writes the sum modulo 2, and carries the rest. The digits come out least significant first, so reverse them at the end.

### Implementation

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int total = carry;
            if (i >= 0) {
                total += a[i--] - '0';
            }
            if (j >= 0) {
                total += b[j--] - '0';
            }
            result += static_cast<char>('0' + total % 2);
            carry = total / 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
```

### Complexity Analysis

* Time complexity: **O(max(m, n))**.
* Space complexity: **O(max(m, n)) for the output**.
