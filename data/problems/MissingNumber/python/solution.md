### Approach

The array holds `n` distinct values drawn from the inclusive range `[0, n]`, which has `n + 1` possible values. Exactly one of them is absent.

Rather than searching for it, compute the sum the range *should* have and subtract the sum of what is actually present. The difference is the missing value.

The closed form for `0 + 1 + ... + n` is `n * (n + 1) / 2`, so the whole problem becomes one pass to accumulate `sum(nums)` and one subtraction.

### Implementation

```python
from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        expected_total = n * (n + 1) // 2
        return expected_total - sum(nums)
```

### Complexity Analysis

* Time complexity: **O(n)** — a single pass to sum the array.
* Space complexity: **O(1)** — no auxiliary storage.

### Notes

* `n * (n + 1) // 2` uses integer division, so the total is always exact; there is no floating point rounding risk.
* At the constraint maximum (`n = 10000`) the expected total is `50,005,000`, which fits comfortably in a 32-bit signed integer, so this approach ports to C++ without overflow concerns.
* An alternative is XOR-folding indices with values (`^` cancels every paired number); it is also O(n) time and O(1) space, but the sum form is simpler to read.
