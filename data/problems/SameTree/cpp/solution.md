### Approach
Perform a depth-first search (DFS) and recursively check nodes for equal values. 

### Implementation

```cpp
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == null && q == null) return p == q;
        return (p.val == q.val) && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
};
```

### Complexity Analysis
* Time complexity : **O(n)**.<br>

* Space complexity : **O(n)**.<br>

