### Approach

Use an iterative approach. Since you can climb either 1 or 2 steps at a time, the number of ways to reach each stair is the sum of the ways to reach the previous two stairs. Start with 1 way for the first stair and 2 ways for the second stair. Then use a loop to calculate the number of ways for each remaining stair. 

### Implementation

```python
class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n

        a = 1
        b = 2

        for i in range(3, n + 1):
            a, b = b, a + b

        return b
```

### Complexity Analysis

* Time complexity: **O(n)**.

  The loop runs once for each stair after the first two, so the number of operations grows linearly with n.

* Space complexity: **O(1)**.

  Only two variables are used to store the previous results, so no additional space is needed as n increases.