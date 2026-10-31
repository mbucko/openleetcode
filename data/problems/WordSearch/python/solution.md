### Approach

Depth-first search from every cell. Match the next letter of the word, temporarily mark the cell as used, explore its four neighbours for the following letter, and restore the cell on the way back. The search succeeds as soon as every letter has been matched.

### Implementation

```python
from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])

        def search(r, c, k):
            if k == len(word):
                return True
            if not (0 <= r < m and 0 <= c < n) or board[r][c] != word[k]:
                return False
            board[r][c] = "#"
            found = (search(r + 1, c, k + 1) or search(r - 1, c, k + 1) or
                     search(r, c + 1, k + 1) or search(r, c - 1, k + 1))
            board[r][c] = word[k]
            return found

        return any(search(r, c, 0) for r in range(m) for c in range(n))
```

### Complexity Analysis

* Time complexity: **O(m * n * 3^L), where L is the word length**.
* Space complexity: **O(L) recursion depth**.
