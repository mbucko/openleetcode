# Reverse Nodes in k-Group

You are given a linked list and a positive integer ``k``. Split the list into consecutive groups of ``k`` nodes and reverse the order of the nodes within each group. If the last group has fewer than ``k`` nodes, leave it as it is. Return the resulting list.

The test runner passes each linked list as an array of values from head to tail, and the result is returned the same way.
\
\
\
**Example 1:**

>**Input:** head = [1,2,3,4,5,6,7], k = 3\
>**Output:** [3,2,1,6,5,4,7]\
>**Explanation:** The groups [1,2,3] and [4,5,6] are reversed, and [7] is too short.

**Example 2:**

>**Input:** head = [8,9], k = 1\
>**Output:** [8,9]\
>**Explanation:** Groups of one node don't change.

**Example 3:**

>**Input:** head = [4,3,2,1], k = 4\
>**Output:** [1,2,3,4]

**Constraints:**

* The list has ``n`` nodes.
* ``1 <= k <= n <= 5000``
* ``0 <= Node.val <= 1000``

**Follow up:** Can you use only ``O(1)`` extra memory?
