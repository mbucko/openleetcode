# Merge k Sorted Lists

You are given an array ``lists`` of ``k`` linked lists, each sorted in non-decreasing order. Merge them all into one sorted list and return it.

The test runner passes each linked list as an array of values from head to tail, and the result is returned the same way.
\
\
\
**Example 1:**

>**Input:** lists = [[2,6,8],[1,3,9],[4]]\
>**Output:** [1,2,3,4,6,8,9]

**Example 2:**

>**Input:** lists = []\
>**Output:** []\
>**Explanation:** There are no lists.

**Example 3:**

>**Input:** lists = [[]]\
>**Output:** []\
>**Explanation:** There is one list, and it is empty.

**Constraints:**

* ``k == lists.length``
* ``0 <= k <= 10^4``
* ``0 <= lists[i].length <= 500``
* ``-10^4 <= lists[i][j] <= 10^4``
* Each ``lists[i]`` is sorted in non-decreasing order.
* The lists have at most ``10^4`` nodes in total.
