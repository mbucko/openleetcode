# Remove Nth Node From End of List

You are given a linked list and an integer ``n``. Remove the ``n``th node counting from the end of the list (the last node is ``n = 1``) and return the resulting list.

The test runner passes each linked list as an array of values from head to tail, and the result is returned the same way.
\
\
\
**Example 1:**

>**Input:** head = [10,20,30,40,50], n = 2\
>**Output:** [10,20,30,50]\
>**Explanation:** The 2nd node from the end holds 40.

**Example 2:**

>**Input:** head = [7], n = 1\
>**Output:** []\
>**Explanation:** Removing the only node leaves an empty list.

**Example 3:**

>**Input:** head = [3,8], n = 2\
>**Output:** [8]

**Constraints:**

* The list has ``sz`` nodes.
* ``1 <= sz <= 30``
* ``0 <= Node.val <= 100``
* ``1 <= n <= sz``

**Follow up:** Can you do it in one pass over the list?
