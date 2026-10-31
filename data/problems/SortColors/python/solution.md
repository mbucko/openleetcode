### Approach

Dutch national flag partitioning with three pointers. Everything before low is 0, everything from low up to mid is 1, and everything after high is 2. Look at nums[mid]: swap a 0 down to low, leave a 1 in place, or swap a 2 up to high. After a swap with high, don't advance mid, because the value that came back hasn't been checked yet.

### Implementation

```python
from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> List[int]:
        low, mid, high = 0, 0, len(nums) - 1
        while mid <= high:
            if nums[mid] == 0:
                nums[low], nums[mid] = nums[mid], nums[low]
                low += 1
                mid += 1
            elif nums[mid] == 1:
                mid += 1
            else:
                nums[mid], nums[high] = nums[high], nums[mid]
                high -= 1
        return nums
```

### Complexity Analysis

* Time complexity: **O(n), one pass**.
* Space complexity: **O(1)**.
