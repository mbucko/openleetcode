# Partition List

You are given a linked list and a value ``x``. Rearrange the list so that every node with a value less than ``x`` comes before every node with a value greater than or equal to ``x``. Within each of the two groups, keep the nodes in their original order. Return the rearranged list.

The test runner passes the linked list as an array of values from head to tail, and the result is returned the same way.
\
\
\
**Example 1:**

>**Input:** head = [5,1,8,2,6,3], x = 4\
>**Output:** [1,2,3,5,8,6]\
>**Explanation:** 1, 2 and 3 are less than 4 and keep their order; so do 5, 8 and 6.

**Example 2:**

>**Input:** head = [3,2], x = 2\
>**Output:** [3,2]

**Example 3:**

>**Input:** head = [], x = 1\
>**Output:** []

**Constraints:**

* The list has between ``0`` and ``200`` nodes.
* ``-100 <= Node.val <= 100``
* ``-200 <= x <= 200``
