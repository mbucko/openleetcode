### Approach

The i-th value of the reflected Gray code has the closed form i XOR (i >> 1). Each bit of the result is set where two neighbouring bits of i differ. Going from i to i + 1 changes exactly one such pair, so neighbours differ in exactly one bit, and the formula reproduces the recursive reflect-and-prefix construction.

### Implementation

```python
from typing import List


class Solution:
    def grayCode(self, n: int) -> List[int]:
        return [i ^ (i >> 1) for i in range(1 << n)]
```

### Complexity Analysis

* Time complexity: **O(2^n)**.
* Space complexity: **O(1) extra, besides the output**.
