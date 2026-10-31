### Approach

Build the result one bit at a time. On each of the 32 iterations, shift the result left by one to make room, copy the lowest bit of `n` into it with `n & 1`, then shift `n` right by one to expose the next bit. After 32 iterations, the bit that started in position 0 has moved to position 31, and so on, so the result is `n` with its bits reversed.

### Implementation

```python
class Solution:
    def reverseBits(self, n: int) -> int:
        result = 0

        for _ in range(32):
            result = (result << 1) | (n & 1)
            n >>= 1

        return result
```

### Complexity Analysis

* Time complexity: **O(1)**. The loop always runs exactly 32 times, regardless of `n`.
* Space complexity: **O(1)**. Only a single integer accumulator is used.
