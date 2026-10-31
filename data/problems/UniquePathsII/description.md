# Unique Paths II

A robot starts at the top-left cell of an ``m x n`` grid and wants to reach the bottom-right cell. It can only move one cell right or one cell down at a time. Some cells are blocked: ``obstacleGrid[i][j]`` is ``1`` for a blocked cell and ``0`` for an open one. The robot can't enter blocked cells.

Return how many different paths it can take. Every answer fits in a 32-bit signed integer.
\
\
\
**Example 1:**

>**Input:** obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]\
>**Output:** 2\
>**Explanation:** The block in the middle leaves only the two paths around the edges.

**Example 2:**

>**Input:** obstacleGrid = [[0,1],[0,0]]\
>**Output:** 1

**Example 3:**

>**Input:** obstacleGrid = [[1]]\
>**Output:** 0\
>**Explanation:** The start itself is blocked.

**Constraints:**

* ``m == obstacleGrid.length``
* ``n == obstacleGrid[i].length``
* ``1 <= m, n <= 100``
* ``obstacleGrid[i][j]`` is ``0`` or ``1``.
