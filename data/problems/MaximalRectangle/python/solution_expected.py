from typing import List


class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        heights = [0] * len(matrix[0])
        best = 0
        for row in matrix:
            for c, cell in enumerate(row):
                heights[c] = heights[c] + 1 if cell == "1" else 0
            stack = []
            for i, h in enumerate(heights + [0]):
                start = i
                while stack and stack[-1][1] >= h:
                    index, height = stack.pop()
                    best = max(best, height * (i - index))
                    start = index
                stack.append((start, h))
        return best
