from typing import List


class Solution:
    def solveSudoku(self, board: List[List[str]]) -> List[List[str]]:
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]
        empty = []
        for r in range(9):
            for c in range(9):
                if board[r][c] == ".":
                    empty.append((r, c))
                else:
                    d = board[r][c]
                    rows[r].add(d)
                    cols[c].add(d)
                    boxes[r // 3 * 3 + c // 3].add(d)

        def solve(k):
            if k == len(empty):
                return True
            r, c = empty[k]
            b = r // 3 * 3 + c // 3
            for d in "123456789":
                if d in rows[r] or d in cols[c] or d in boxes[b]:
                    continue
                board[r][c] = d
                rows[r].add(d)
                cols[c].add(d)
                boxes[b].add(d)
                if solve(k + 1):
                    return True
                rows[r].remove(d)
                cols[c].remove(d)
                boxes[b].remove(d)
            board[r][c] = "."
            return False

        solve(0)
        return board
