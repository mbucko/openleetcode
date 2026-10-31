from typing import List


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        n = len(grid[0])
        row = [float("inf")] * n
        row[0] = 0
        for grid_row in grid:
            row[0] += grid_row[0]
            for c in range(1, n):
                row[c] = min(row[c], row[c - 1]) + grid_row[c]
        return row[-1]
