### Approach

Reverse just the sublist between the two positions. With real nodes: walk to the node before position left, then repeatedly take the node after the reversed section and move it to the front of that section, right - left times. The section ends up reversed and already connected at both ends, in one pass.

### Implementation

```cpp
class Solution {
public:
    vector<int> reverseBetween(vector<int>& head, int left, int right) {
        reverse(head.begin() + left - 1, head.begin() + right);
        return head;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
