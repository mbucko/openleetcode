# Minimum Path Sum

You are given an ``m x n`` grid of non-negative integers. Find a path from the top-left cell to the bottom-right cell that only moves right or down, such that the sum of the numbers along it (including both corners) is as small as possible. Return that sum.
\
\
\
**Example 1:**

>**Input:** grid = [[1,4,1],[2,7,1],[5,3,1]]\
>**Output:** 8\
>**Explanation:** The path 1 -> 4 -> 1 -> 1 -> 1 adds up to 8.

**Example 2:**

>**Input:** grid = [[2,3,4]]\
>**Output:** 9

**Constraints:**

* ``m == grid.length``
* ``n == grid[i].length``
* ``1 <= m, n <= 200``
* ``0 <= grid[i][j] <= 200``
