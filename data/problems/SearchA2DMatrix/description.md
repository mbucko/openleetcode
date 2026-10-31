# Search a 2D Matrix

You are given an ``m x n`` integer matrix where each row is sorted in ascending order and the first value of each row is larger than the last value of the row before it. Given an integer ``target``, return ``true`` if it appears in the matrix.

Your algorithm must run in ``O(log(m * n))`` time.
\
\
\
**Example 1:**

>**Input:** matrix = [[2,4,6],[9,11,15],[20,25,31]], target = 11\
>**Output:** true

**Example 2:**

>**Input:** matrix = [[2,4,6],[9,11,15],[20,25,31]], target = 7\
>**Output:** false

**Example 3:**

>**Input:** matrix = [[5]], target = 5\
>**Output:** true

**Constraints:**

* ``m == matrix.length``
* ``n == matrix[i].length``
* ``1 <= m, n <= 100``
* ``-10^4 <= matrix[i][j], target <= 10^4``
