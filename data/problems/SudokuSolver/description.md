# Sudoku Solver

You are given a ``9 x 9`` Sudoku puzzle. Filled cells hold a digit from ``"1"`` to ``"9"`` and empty cells hold ``"."``. Fill every empty cell so the board follows the Sudoku rules:

* Each row contains the digits ``1`` to ``9`` at most once.
* Each column contains the digits ``1`` to ``9`` at most once.
* Each of the nine ``3 x 3`` boxes contains the digits ``1`` to ``9`` at most once.

Every puzzle has exactly one solution. Return the solved board.
\
\
\
**Example 1:**

>**Input:** board = [["3","4","5","6","7","8",".",".","."],[".","7","8","9",".",".","3",".","."],["9",".","2",".",".","5","6",".","."],[".","5","6",".",".",".","1",".","."],[".",".","9","1",".","3",".",".","."],[".",".","3","4",".","6",".","8","9"],[".",".",".","8","9","1","2","3","4"],[".",".","1",".","3",".","5",".","7"],[".","3",".","5","6","7",".","9","1"]]\
>**Output:** [["3","4","5","6","7","8","9","1","2"],["6","7","8","9","1","2","3","4","5"],["9","1","2","3","4","5","6","7","8"],["4","5","6","7","8","9","1","2","3"],["7","8","9","1","2","3","4","5","6"],["1","2","3","4","5","6","7","8","9"],["5","6","7","8","9","1","2","3","4"],["8","9","1","2","3","4","5","6","7"],["2","3","4","5","6","7","8","9","1"]]

**Constraints:**

* ``board.length == 9``
* ``board[i].length == 9``
* ``board[i][j]`` is a digit ``1``-``9`` or ``'.'``.
* The puzzle has exactly one solution.
