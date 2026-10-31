# Rotate List

You are given a linked list and a non-negative integer ``k``. Rotate the list to the right by ``k`` places: each step moves the last node to the front. Return the rotated list.

The test runner passes the linked list as an array of values from head to tail, and the result is returned the same way.
\
\
\
**Example 1:**

>**Input:** head = [10,20,30,40], k = 1\
>**Output:** [40,10,20,30]

**Example 2:**

>**Input:** head = [10,20,30,40], k = 6\
>**Output:** [30,40,10,20]\
>**Explanation:** Rotating by 4 gives back the same list, so 6 is the same as 2.

**Example 3:**

>**Input:** head = [], k = 3\
>**Output:** []

**Constraints:**

* The list has between ``0`` and ``500`` nodes.
* ``-100 <= Node.val <= 100``
* ``0 <= k <= 2 * 10^9``
