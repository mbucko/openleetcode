# Remove Duplicates from Sorted List II

You are given a sorted linked list. Delete **every** node whose value appears more than once, so that only the values that appeared exactly once remain. Return the resulting list, still sorted.

The test runner passes the linked list as an array of values from head to tail, and the result is returned the same way.
\
\
\
**Example 1:**

>**Input:** head = [1,2,2,3,4,4,5]\
>**Output:** [1,3,5]\
>**Explanation:** 2 and 4 appear more than once, so all their nodes are deleted.

**Example 2:**

>**Input:** head = [7,7,7,8]\
>**Output:** [8]

**Example 3:**

>**Input:** head = [6,6]\
>**Output:** []

**Constraints:**

* The list has between ``0`` and ``300`` nodes.
* ``-100 <= Node.val <= 100``
* The list is sorted in ascending order.
