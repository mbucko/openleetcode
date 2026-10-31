### Approach

Pick each value as the root in turn. The smaller values must form the left subtree and the larger values the right subtree, so build every tree for each side recursively and combine every left with every right. A tree's preorder is its root followed by the left subtree's preorder and then the right subtree's. Sort the results at the end.

### Implementation

```python
from typing import List


class Solution:
    def generateTrees(self, n: int) -> List[List[int]]:
        def build(low, high):
            if low > high:
                return [[]]
            trees = []
            for root in range(low, high + 1):
                for left in build(low, root - 1):
                    for right in build(root + 1, high):
                        trees.append([root] + left + right)
            return trees

        return sorted(build(1, n))
```

### Complexity Analysis

* Time complexity: **O(n * C_n), where C_n is the n-th Catalan number**.
* Space complexity: **O(n * C_n) for the output**.
