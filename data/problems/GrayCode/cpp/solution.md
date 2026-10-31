### Approach

The i-th value of the reflected Gray code has the closed form i XOR (i >> 1). Each bit of the result is set where two neighbouring bits of i differ. Going from i to i + 1 changes exactly one such pair, so neighbours differ in exactly one bit, and the formula reproduces the recursive reflect-and-prefix construction.

### Implementation

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        for (int i = 0; i < (1 << n); ++i) {
            result.push_back(i ^ (i >> 1));
        }
        return result;
    }
};
```

### Complexity Analysis

* Time complexity: **O(2^n)**.
* Space complexity: **O(1) extra, besides the output**.
