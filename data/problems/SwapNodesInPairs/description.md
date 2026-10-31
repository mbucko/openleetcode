# Swap Nodes in Pairs

You are given a linked list. Swap every two adjacent nodes (the 1st with the 2nd, the 3rd with the 4th, and so on) and return the list. If the list has an odd number of nodes, the last one stays where it is. Swap the nodes themselves, not just their values.

The test runner passes each linked list as an array of values from head to tail, and the result is returned the same way.
\
\
\
**Example 1:**

>**Input:** head = [5,6,7,8]\
>**Output:** [6,5,8,7]

**Example 2:**

>**Input:** head = [9,4,2]\
>**Output:** [4,9,2]\
>**Explanation:** The last node has no partner, so it stays in place.

**Example 3:**

>**Input:** head = []\
>**Output:** []

**Constraints:**

* The list has between ``0`` and ``100`` nodes.
* ``0 <= Node.val <= 100``
