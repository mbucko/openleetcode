# Spiral Matrix

You are given an ``m x n`` matrix. Return all of its elements in spiral order: go right along the top row, down the right column, left along the bottom row, up the left column, and repeat inwards until every element is visited.
\
\
\
**Example 1:**

>**Input:** matrix = [[1,2,3],[8,9,4],[7,6,5]]\
>**Output:** [1,2,3,4,5,6,7,8,9]\
>**Explanation:** The values are laid out so the spiral visits them in order.

**Example 2:**

>**Input:** matrix = [[1,2,3,4],[5,6,7,8]]\
>**Output:** [1,2,3,4,8,7,6,5]

**Example 3:**

>**Input:** matrix = [[3],[2],[1]]\
>**Output:** [3,2,1]

**Constraints:**

* ``m == matrix.length``
* ``n == matrix[i].length``
* ``1 <= m, n <= 10``
* ``-100 <= matrix[i][j] <= 100``
