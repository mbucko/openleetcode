# Reverse Linked List II

You are given a linked list and two positions ``left <= right``, counting from 1. Reverse the nodes from position ``left`` through position ``right`` and return the list. The rest of the list stays as it is.

The test runner passes the linked list as an array of values from head to tail, and the result is returned the same way.
\
\
\
**Example 1:**

>**Input:** head = [10,20,30,40,50,60], left = 2, right = 5\
>**Output:** [10,50,40,30,20,60]\
>**Explanation:** Positions 2 to 5 hold 20, 30, 40 and 50, which come out reversed.

**Example 2:**

>**Input:** head = [7], left = 1, right = 1\
>**Output:** [7]

**Example 3:**

>**Input:** head = [1,2,3], left = 1, right = 3\
>**Output:** [3,2,1]

**Constraints:**

* The list has ``n`` nodes.
* ``1 <= n <= 500``
* ``-500 <= Node.val <= 500``
* ``1 <= left <= right <= n``

**Follow up:** Can you do it in one pass?
