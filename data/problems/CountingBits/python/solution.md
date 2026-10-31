### Approach

Use dynamic programming to calculate the number of set bits for each
integer from 0 through n.

For each positive integer i, divide it by 2. The number of set bits
in i is the number of set bits in i // 2, plus 1 if i is odd.

### Implementation

The answer array starts with zeros. Each value is calculated using
the previously computed value at i // 2.

### Complexity Analysis

* Time complexity: O(n).
* Space complexity: O(n).
