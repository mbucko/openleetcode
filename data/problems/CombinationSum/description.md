# Combination Sum

You are given an array of distinct positive integers ``candidates`` and a positive integer ``target``. Return every distinct combination of candidates that adds up to ``target``. The same candidate may be used any number of times.

Write each combination in ascending order and list the combinations in ascending lexicographic order.
\
\
\
**Example 1:**

>**Input:** candidates = [3,4,5], target = 8\
>**Output:** [[3,5],[4,4]]\
>**Explanation:** 3 + 5 = 8 and 4 + 4 = 8.

**Example 2:**

>**Input:** candidates = [2,5], target = 9\
>**Output:** [[2,2,5]]

**Example 3:**

>**Input:** candidates = [4], target = 3\
>**Output:** []

**Constraints:**

* ``1 <= candidates.length <= 30``
* ``2 <= candidates[i] <= 40``
* All values in ``candidates`` are distinct.
* ``1 <= target <= 40``
