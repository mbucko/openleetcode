class Solution:
    def totalNQueens(self, n: int) -> int:
        def count(row, cols, diag, anti):
            if row == n:
                return 1
            total = 0
            for col in range(n):
                if col in cols or row - col in diag or row + col in anti:
                    continue
                total += count(row + 1, cols | {col}, diag | {row - col}, anti | {row + col})
            return total

        return count(0, frozenset(), frozenset(), frozenset())
