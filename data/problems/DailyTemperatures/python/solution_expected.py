from typing import List

class Solution(object):
    def dailyTemperatures(self, temps: List[int]) -> List[int]:
        n = len(temps)
        answer = [0] * n
        stack = []

        for i, temp in enumerate(temps):
            while stack and temps[stack[-1]] < temp:
                prev = stack.pop()
                answer[prev] = i - prev
            stack.append(i)

        return answer