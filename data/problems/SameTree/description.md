# Same Tree

You are given the roots of two binary trees ``p`` and ``q``. Return ``true`` if they are identical: same shape, and the same value in every corresponding node.

Trees are written in level order, with ``null`` marking a missing child.
\
\
\
**Example 1:**

>**Input:** p = [4,7,9], q = [4,7,9]\
>**Output:** true

**Example 2:**

>**Input:** p = [4,7], q = [4,null,7]\
>**Output:** false\
>**Explanation:** The 7 is a left child in one tree and a right child in the other.

**Example 3:**

>**Input:** p = [5,1,2], q = [5,2,1]\
>**Output:** false

**Constraints:**

* Each tree has between ``0`` and ``100`` nodes.
* ``-10^4 <= Node.val <= 10^4``
