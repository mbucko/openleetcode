# Maximal Rectangle

You are given an ``m x n`` grid ``matrix`` of ``"0"`` and ``"1"`` characters. Return the area of the largest rectangle made up only of ``"1"`` cells.
\
\
\
**Example 1:**

>**Input:** matrix = [["1","1","0"],["1","1","1"],["0","1","1"]]\
>**Output:** 4\
>**Explanation:** The top-left 2 x 2 block is all 1s.

**Example 2:**

>**Input:** matrix = [["0"]]\
>**Output:** 0

**Example 3:**

>**Input:** matrix = [["1","1","1","1"]]\
>**Output:** 4

**Constraints:**

* ``m == matrix.length``
* ``n == matrix[i].length``
* ``1 <= m, n <= 200``
* ``matrix[i][j]`` is ``'0'`` or ``'1'``.
