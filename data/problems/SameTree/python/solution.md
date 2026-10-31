### Approach

Perform a depth-first search (DFS) and recursively check nodes for equal values. 

### Implementation

```python
# Definition for a binary tree node.
# class TreeNode:
#    def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from treenode import TreeNode

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if (p is None or q is None):
            return p == q
        
        if (p.val != q.val):
            return False
        
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(n)**.
