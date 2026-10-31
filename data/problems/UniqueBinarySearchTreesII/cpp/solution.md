### Approach

Pick each value as the root in turn. The smaller values must form the left subtree and the larger values the right subtree, so build every tree for each side recursively and combine every left with every right. A tree's preorder is its root followed by the left subtree's preorder and then the right subtree's. Sort the results at the end.

### Implementation

```cpp
class Solution {
public:
    vector<vector<int>> generateTrees(int n) {
        vector<vector<int>> trees = build(1, n);
        sort(trees.begin(), trees.end());
        return trees;
    }

private:
    vector<vector<int>> build(int low, int high) {
        if (low > high) {
            return {{}};
        }
        vector<vector<int>> trees;
        for (int root = low; root <= high; ++root) {
            for (const auto& left : build(low, root - 1)) {
                for (const auto& right : build(root + 1, high)) {
                    vector<int> tree = {root};
                    tree.insert(tree.end(), left.begin(), left.end());
                    tree.insert(tree.end(), right.begin(), right.end());
                    trees.push_back(move(tree));
                }
            }
        }
        return trees;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n * C_n), where C_n is the n-th Catalan number**.
* Space complexity: **O(n * C_n) for the output**.
