from typing import List


class Solution:
    def generateTrees(self, n: int) -> List[List[int]]:
        def build(low, high):
            if low > high:
                return [[]]
            trees = []
            for root in range(low, high + 1):
                for left in build(low, root - 1):
                    for right in build(root + 1, high):
                        trees.append([root] + left + right)
            return trees

        return sorted(build(1, n))
