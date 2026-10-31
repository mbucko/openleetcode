class Solution:
    def numTrees(self, n: int) -> int:
        count = [1] * (n + 1)
        for size in range(2, n + 1):
            count[size] = sum(count[root - 1] * count[size - root] for root in range(1, size + 1))
        return count[n]
