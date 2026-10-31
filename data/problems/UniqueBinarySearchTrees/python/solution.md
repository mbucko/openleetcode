### Approach

Choosing root r splits the values into r - 1 smaller ones on the left and size - r larger ones on the right, and the two sides can be shaped independently. So the number of trees on size values is the sum, over every root, of left count times right count. Build the counts up from size 0. These are the Catalan numbers.

### Implementation

```python
class Solution:
    def numTrees(self, n: int) -> int:
        count = [1] * (n + 1)
        for size in range(2, n + 1):
            count[size] = sum(count[root - 1] * count[size - root] for root in range(1, size + 1))
        return count[n]
```

### Complexity Analysis

* Time complexity: **O(n^2)**.
* Space complexity: **O(n)**.
