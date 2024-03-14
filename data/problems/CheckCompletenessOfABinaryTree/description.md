# Check Completeness of a Binary Tree

Check if the given binary tree root forms a complete binary tree.

A complete binary tree is characterized by each level being fully filled except potentially the last level. However, all nodes in the last level should be aligned to the left. The last level, `h`, can have between `1` and `2h` nodes.
\
\
\
**Example 1:**
>**Input:** root = [1,2,3,4,5,6]\
>**Output:** true\
>**Explanation:** All levels preceding the final one are completely filled (for instance, levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are aligned to the left as much as possible.

**Example 2:**
>**Input:** root = [1,2,3,4,5,null,7]\
>**Output:** false\
>**Explanation:** The node with value 7 isn't as far left as possible.
 
**Constraints:**

* The number of nodes in the tree is in the range ``[1, 100]``.
* ``1 <= Node.val <= 1000``