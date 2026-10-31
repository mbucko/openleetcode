### Approach

Walk the list two nodes at a time and swap each pair. With real nodes this means relinking: the node before the pair points to the second node, the second points to the first, and the first points to whatever followed the pair.

### Implementation

```cpp
class Solution {
public:
    vector<int> swapPairs(vector<int>& head) {
        for (size_t i = 0; i + 1 < head.size(); i += 2) {
            swap(head[i], head[i + 1]);
        }
        return head;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
