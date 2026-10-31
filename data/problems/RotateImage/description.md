# Rotate Image

You are given an ``n x n`` matrix representing an image. Rotate it by 90 degrees clockwise **in place**, without allocating another matrix, and return it.
\
\
\
**Example 1:**

>**Input:** matrix = [[1,2],[3,4]]\
>**Output:** [[3,1],[4,2]]\
>**Explanation:** The left column [3,1], read bottom to top, becomes the top row.

**Example 2:**

>**Input:** matrix = [[5,1,9],[2,4,8],[13,3,6]]\
>**Output:** [[13,2,5],[3,4,1],[6,8,9]]

**Example 3:**

>**Input:** matrix = [[7]]\
>**Output:** [[7]]

**Constraints:**

* ``n == matrix.length == matrix[i].length``
* ``1 <= n <= 20``
* ``-1000 <= matrix[i][j] <= 1000``
