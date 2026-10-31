### Approach

Simulate the zigzag. Keep one string per row and a current row that moves down until the last row, then up until the first row. Append each character to its row, then join the rows.

### Implementation

```python
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s
        rows = [[] for _ in range(numRows)]
        row = 0
        step = 1
        for ch in s:
            rows[row].append(ch)
            if row == 0:
                step = 1
            elif row == numRows - 1:
                step = -1
            row += step
        return "".join("".join(r) for r in rows)
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(n)**.
