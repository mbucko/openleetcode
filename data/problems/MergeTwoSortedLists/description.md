# Merge Two Sorted Lists

You are given two linked lists ``list1`` and ``list2``, each sorted in non-decreasing order. Merge them into one sorted list that contains all of their nodes, and return it.

The test runner passes each linked list as an array of values from head to tail, and the result is returned the same way.
\
\
\
**Example 1:**

>**Input:** list1 = [2,5,9], list2 = [1,5,6]\
>**Output:** [1,2,5,5,6,9]

**Example 2:**

>**Input:** list1 = [], list2 = []\
>**Output:** []

**Example 3:**

>**Input:** list1 = [], list2 = [4]\
>**Output:** [4]

**Constraints:**

* Each list has between ``0`` and ``50`` nodes.
* ``-100 <= Node.val <= 100``
* Both lists are sorted in non-decreasing order.
