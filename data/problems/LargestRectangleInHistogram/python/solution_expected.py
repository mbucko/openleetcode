from typing import List


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        best = 0
        for i, h in enumerate(heights + [0]):
            start = i
            while stack and stack[-1][1] >= h:
                index, height = stack.pop()
                best = max(best, height * (i - index))
                start = index
            stack.append((start, h))
        return best
