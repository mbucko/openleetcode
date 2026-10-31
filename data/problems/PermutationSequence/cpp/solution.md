### Approach

Count instead of generating. With r digits left, each choice of first digit starts a block of (r - 1)! orderings. Dividing the zero-based k by (r - 1)! tells you which unused digit comes next, and the remainder is the position within that block. Repeat for each position.

### Implementation

```cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        string digits;
        vector<int> factorial(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            digits += static_cast<char>('0' + i);
            factorial[i] = factorial[i - 1] * i;
        }
        --k;
        string result;
        for (int remaining = n; remaining > 0; --remaining) {
            const int index = k / factorial[remaining - 1];
            k %= factorial[remaining - 1];
            result += digits[index];
            digits.erase(digits.begin() + index);
        }
        return result;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n^2)**.
* Space complexity: **O(n)**.
