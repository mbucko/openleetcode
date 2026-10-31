### Approach

Choosing root r splits the values into r - 1 smaller ones on the left and size - r larger ones on the right, and the two sides can be shaped independently. So the number of trees on size values is the sum, over every root, of left count times right count. Build the counts up from size 0. These are the Catalan numbers.

### Implementation

```cpp
class Solution {
public:
    int numTrees(int n) {
        vector<long long> count(n + 1, 0);
        count[0] = 1;
        count[1] = 1;
        for (int size = 2; size <= n; ++size) {
            for (int root = 1; root <= size; ++root) {
                count[size] += count[root - 1] * count[size - root];
            }
        }
        return static_cast<int>(count[n]);
    }
};
```

### Complexity Analysis

* Time complexity: **O(n^2)**.
* Space complexity: **O(n)**.
