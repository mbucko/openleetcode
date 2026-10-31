# Word Search

You are given an ``m x n`` grid of letters ``board`` and a string ``word``. Return ``true`` if ``word`` can be traced through the grid: start on any cell, and step each time to a horizontally or vertically adjacent cell, spelling the word one letter per cell. A cell may be used at most once.
\
\
\
**Example 1:**

>**Input:** board = [["C","A","T"],["X","R","S"],["D","O","G"]], word = "CARS"\
>**Output:** true\
>**Explanation:** C (0,0), A (0,1), R (1,1), S (1,2).

**Example 2:**

>**Input:** board = [["C","A","T"],["X","R","S"],["D","O","G"]], word = "TAC"\
>**Output:** true

**Example 3:**

>**Input:** board = [["C","A","T"],["X","R","S"],["D","O","G"]], word = "COG"\
>**Output:** false\
>**Explanation:** C and O are not adjacent.

**Constraints:**

* ``m == board.length``
* ``n == board[i].length``
* ``1 <= m, n <= 6``
* ``1 <= word.length <= 15``
* ``board`` and ``word`` contain only English letters.
