from typing import List


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        result = []
        current = []

        def build(start):
            if len(current) == k:
                result.append(list(current))
                return
            for value in range(start, n - (k - len(current)) + 2):
                current.append(value)
                build(value + 1)
                current.pop()

        build(1)
        return result
