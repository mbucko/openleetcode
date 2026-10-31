# Unique Binary Search Trees II

You are given an integer ``n``. Find every structurally different binary search tree that stores exactly the values ``1`` to ``n``.

A binary search tree storing ``1`` to ``n`` is fully determined by its **preorder** traversal (node, then left subtree, then right subtree). Return the preorder traversal of each tree, listed in ascending lexicographic order.
\
\
\
**Example 1:**

>**Input:** n = 2\
>**Output:** [[1,2],[2,1]]\
>**Explanation:** Value 1 can be the root with 2 on its right, or 2 can be the root with 1 on its left.

**Example 2:**

>**Input:** n = 4\
>**Output:** [[1,2,3,4],[1,2,4,3],[1,3,2,4],[1,4,2,3],[1,4,3,2],[2,1,3,4],[2,1,4,3],[3,1,2,4],[3,2,1,4],[4,1,2,3],[4,1,3,2],[4,2,1,3],[4,3,1,2],[4,3,2,1]]

**Constraints:**

* ``1 <= n <= 8``
