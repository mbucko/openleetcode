from typing import List


class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        matrix = [[0] * n for _ in range(n)]
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        r = c = d = 0
        for value in range(1, n * n + 1):
            matrix[r][c] = value
            dr, dc = directions[d]
            if not (0 <= r + dr < n and 0 <= c + dc < n and matrix[r + dr][c + dc] == 0):
                d = (d + 1) % 4
                dr, dc = directions[d]
            r, c = r + dr, c + dc
        return matrix
