# Number of Islands

Given a binary grid of size ```m x n``` that represents a map, where ```'1'``` signifies land and ```'0'``` signifies water, calculate and return the total number of islands present.

An island is surrounded by water and is formed by connecting neightbouring lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
<br>
<br>
<br>
***Example 1:***

&emsp;&emsp;***Input:*** grid = [<br>
&emsp;&emsp;&emsp;&emsp;["1","1","1","1","0"],<br>
&emsp;&emsp;&emsp;&emsp;["1","1","0","1","0"],<br>
&emsp;&emsp;&emsp;&emsp;["1","1","0","0","0"],<br>
&emsp;&emsp;&emsp;&emsp;["0","0","0","0","0"]<br>
&emsp;&emsp;]<br>
&emsp;&emsp;***Output:*** 1

***Example 2:***

&emsp;&emsp;***Input:*** grid = [<br>
&emsp;&emsp;&emsp;&emsp;["1","1","0","0","0"],<br>
&emsp;&emsp;&emsp;&emsp;["1","1","0","0","0"],<br>
&emsp;&emsp;&emsp;&emsp;["0","0","1","0","0"],<br>
&emsp;&emsp;&emsp;&emsp;["0","0","0","1","1"]<br>
&emsp;&emsp;]<br>
&emsp;&emsp;***Output:*** 3
 

***Constraints:***

* ``m == grid.length``
* ``n == grid[i].length``
* ``1 <= m, n <= 300``
* ``grid[i][j] is '0' or '1'``