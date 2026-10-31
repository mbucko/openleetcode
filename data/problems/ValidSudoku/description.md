# Valid Sudoku

You are given a ``9 x 9`` Sudoku board. Filled cells hold a digit from ``"1"`` to ``"9"`` and empty cells hold ``"."``. Return ``true`` if the filled cells follow the Sudoku rules:

* Each row contains the digits ``1`` to ``9`` at most once.
* Each column contains the digits ``1`` to ``9`` at most once.
* Each of the nine ``3 x 3`` boxes contains the digits ``1`` to ``9`` at most once.

Only check the filled cells. The board doesn't have to be solvable.
\
\
\
**Example 1:**

>**Input:** board = [[".","7",".","9",".",".","3",".","."],[".","1",".",".","4","5",".",".","8"],[".",".","5",".",".",".","9",".","2"],["7","8",".",".","2","3",".",".","."],[".",".",".",".",".",".",".",".","."],["4",".","6","7","8",".",".",".","."],[".",".",".",".",".","4","5",".","."],[".",".",".","5","6","7",".",".","."],[".",".","7",".",".",".","2","3","."]]\
>**Output:** true\
>**Explanation:** No digit repeats in any row, column or box.

**Example 2:**

>**Input:** board = [[".","7",".","9","7",".","3",".","."],[".","1",".",".","4","5",".",".","8"],[".",".","5",".",".",".","9",".","2"],["7","8",".",".","2","3",".",".","."],[".",".",".",".",".",".",".",".","."],["4",".","6","7","8",".",".",".","."],[".",".",".",".",".","4","5",".","."],[".",".",".","5","6","7",".",".","."],[".",".","7",".",".",".","2","3","."]]\
>**Output:** false\
>**Explanation:** One row contains the same digit twice.

**Example 3:**

>**Input:** board = [[".",".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".",".","."]]\
>**Output:** true\
>**Explanation:** An empty board breaks no rules.

**Constraints:**

* ``board.length == 9``
* ``board[i].length == 9``
* ``board[i][j]`` is a digit ``1``-``9`` or ``'.'``.
