# N-Queens

Place ``n`` queens on an ``n x n`` chessboard so that no two attack each other: no two share a row, a column or a diagonal.

Return every such placement. Write each board as ``n`` strings, one per row, where ``'Q'`` is a queen and ``'.'`` is an empty square. Order the boards by the queen's column in the first row, then by the queen's column in the second row, and so on.
\
\
\
**Example 1:**

>**Input:** n = 4\
>**Output:** [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]\
>**Explanation:** There are two placements on a 4 x 4 board.

**Example 2:**

>**Input:** n = 1\
>**Output:** [["Q"]]

**Example 3:**

>**Input:** n = 3\
>**Output:** []\
>**Explanation:** No placement works on a 3 x 3 board.

**Constraints:**

* ``1 <= n <= 9``
