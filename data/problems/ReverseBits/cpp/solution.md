### Approach

Take the lowest bit of the input 32 times. Each time, shift the result left and append that bit, then shift the input right.

### Implementation

```cpp
class Solution {
public:
    int reverseBits(int n) {
        uint32_t value = n;
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result = (result << 1) | (value & 1);
            value >>= 1;
        }
        return static_cast<int>(result);
    }
};
```

### Complexity Analysis

* Time complexity: **O(1), always 32 iterations**.
* Space complexity: **O(1)**.
