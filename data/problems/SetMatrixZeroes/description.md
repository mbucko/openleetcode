# Set Matrix Zeroes

You are given an ``m x n`` integer matrix. Wherever an element is ``0``, set its entire row and its entire column to ``0``. Do it **in place** and return the matrix.

Only the zeros in the original matrix count. Zeros you write don't spread any further.
\
\
\
**Example 1:**

>**Input:** matrix = [[1,2,3],[4,0,6],[7,8,9]]\
>**Output:** [[1,0,3],[0,0,0],[7,0,9]]\
>**Explanation:** The 0 clears the middle row and the middle column.

**Example 2:**

>**Input:** matrix = [[0,5],[6,7]]\
>**Output:** [[0,0],[0,7]]

**Example 3:**

>**Input:** matrix = [[3,4]]\
>**Output:** [[3,4]]

**Constraints:**

* ``m == matrix.length``
* ``n == matrix[0].length``
* ``1 <= m, n <= 200``
* ``-2^31 <= matrix[i][j] <= 2^31 - 1``

**Follow up:** Can you use only ``O(1)`` extra space?
