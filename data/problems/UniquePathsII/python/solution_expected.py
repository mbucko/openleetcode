from typing import List


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        n = len(obstacleGrid[0])
        row = [0] * n
        row[0] = 1
        for grid_row in obstacleGrid:
            for c in range(n):
                if grid_row[c] == 1:
                    row[c] = 0
                elif c > 0:
                    row[c] += row[c - 1]
        return row[-1]
