# Validate Binary Search Tree

You are given the root of a binary tree. Return ``true`` if it is a valid binary search tree:

* Every value in a node's left subtree is **strictly less** than the node's value.
* Every value in a node's right subtree is **strictly greater** than the node's value.
* Both subtrees are valid binary search trees themselves.

Trees are written in level order, with ``null`` marking a missing child.
\
\
\
**Example 1:**

>**Input:** root = [8,4,12,2,6]\
>**Output:** true

**Example 2:**

>**Input:** root = [8,4,12,null,null,7,15]\
>**Output:** false\
>**Explanation:** 7 is in the right subtree of 8 but is smaller than 8.

**Example 3:**

>**Input:** root = [3,3]\
>**Output:** false\
>**Explanation:** Equal values are not allowed.

**Constraints:**

* The tree has between ``1`` and ``10^4`` nodes.
* ``-2^31 <= Node.val <= 2^31 - 1``
