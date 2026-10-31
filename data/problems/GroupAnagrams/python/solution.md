### Approach

Two strings are anagrams exactly when their letters, sorted, are the same. Use the sorted letters as a key in a hash map and collect the strings under their key. Then sort each group and sort the list of groups.

### Implementation

```python
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = {}
        for word in strs:
            groups.setdefault("".join(sorted(word)), []).append(word)
        return sorted(sorted(group) for group in groups.values())
```

### Complexity Analysis

* Time complexity: **O(n * k log k), where k is the longest string length**.
* Space complexity: **O(n * k)**.
