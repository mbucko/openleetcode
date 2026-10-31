# Recover Binary Search Tree

You are given the root of a binary search tree in which the values of **exactly two** nodes were swapped by mistake. All values are distinct.

Find the two swapped values and return them as ``[smaller, larger]``. Swapping these two values back would restore a valid binary search tree.

Trees are written in level order, with ``null`` marking a missing child.
\
\
\
**Example 1:**

>**Input:** root = [8,4,12,2,10,6,14]\
>**Output:** [6,10]\
>**Explanation:** Swapping 6 and 10 back gives the valid tree [8,4,12,2,6,10,14].

**Example 2:**

>**Input:** root = [7,2,5,null,3]\
>**Output:** [5,7]\
>**Explanation:** 5 and 7 are next to each other in sorted order, so only one pair is out of place.

**Example 3:**

>**Input:** root = [2,3,1]\
>**Output:** [1,3]\
>**Explanation:** The root's children are in the wrong places, so 1 and 3 were swapped.

**Constraints:**

* The tree has between ``2`` and ``1000`` nodes.
* ``-2^31 <= Node.val <= 2^31 - 1``
* All values are distinct.
* Exactly two values were swapped.

**Follow up:** Can you do it with ``O(1)`` extra space?
