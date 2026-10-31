# Binary Tree Inorder Traversal

You are given the root of a binary tree. Return its node values in **inorder**: for every node, first its left subtree, then the node itself, then its right subtree.

Trees are written in level order, with ``null`` marking a missing child.
\
\
\
**Example 1:**

>**Input:** root = [4,2,6,1,3]\
>**Output:** [1,2,3,4,6]

**Example 2:**

>**Input:** root = [6,null,8,7]\
>**Output:** [6,7,8]\
>**Explanation:** 6 has no left child. Its right child 8 has left child 7, so 7 comes before 8.

**Example 3:**

>**Input:** root = []\
>**Output:** []

**Constraints:**

* The tree has between ``0`` and ``100`` nodes.
* ``-100 <= Node.val <= 100``

**Follow up:** The recursive solution is short. Can you do it iteratively?
