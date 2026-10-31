### Approach

Build the lines one at a time. Greedily take words while their lengths plus one space per gap still fit. For a normal line, split the leftover spaces evenly across the gaps, with the first (leftover mod gaps) gaps getting one extra. The last line and single-word lines are joined with single spaces and padded on the right instead.

### Implementation

```python
from typing import List


class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        lines = []
        i = 0
        while i < len(words):
            j = i
            width = 0
            while j < len(words) and width + len(words[j]) + (j - i) <= maxWidth:
                width += len(words[j])
                j += 1
            gaps = j - i - 1
            if j == len(words) or gaps == 0:
                line = " ".join(words[i:j])
                lines.append(line + " " * (maxWidth - len(line)))
            else:
                spaces, extra = divmod(maxWidth - width, gaps)
                line = ""
                for k in range(i, j - 1):
                    line += words[k] + " " * (spaces + (1 if k - i < extra else 0))
                lines.append(line + words[j - 1])
            i = j
        return lines
```

### Complexity Analysis

* Time complexity: **O(total characters)**.
* Space complexity: **O(maxWidth) besides the output**.
