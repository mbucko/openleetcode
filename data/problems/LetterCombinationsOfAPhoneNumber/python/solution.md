### Approach

Build the combinations one digit at a time. Start with a single empty string, and for each digit extend every string so far with each of that digit's letters. The keypad letters are in alphabetical order and earlier digits vary slowest, so the result comes out in lexicographic order.

### Implementation

```python
from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        keypad = {"2": "abc", "3": "def", "4": "ghi", "5": "jkl",
                  "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"}
        result = [""]
        for digit in digits:
            result = [prefix + letter for prefix in result for letter in keypad[digit]]
        return result
```

### Complexity Analysis

* Time complexity: **O(4^n * n)**.
* Space complexity: **O(4^n * n) for the output**.
