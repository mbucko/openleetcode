### Approach

Start with the first string as the candidate prefix. For each other string, shorten the candidate until that string starts with it. Whatever is left at the end is common to all of them.

### Implementation

```python
from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = strs[0]
        for word in strs[1:]:
            while not word.startswith(prefix):
                prefix = prefix[:-1]
        return prefix
```

### Complexity Analysis

* Time complexity: **O(S), where S is the total number of characters**.
* Space complexity: **O(1) extra, besides the result**.
