### Approach

Use two pointers n nodes apart. Move the lead pointer n steps ahead, then move both until the lead reaches the end. The trailing pointer then sits on the node to remove. This finds it in a single pass without knowing the length in advance.

### Implementation

```cpp
class Solution {
public:
    vector<int> removeNthFromEnd(vector<int>& head, int n) {
        size_t lead = n;
        size_t trail = 0;
        while (lead < head.size()) {
            ++lead;
            ++trail;
        }
        head.erase(head.begin() + trail);
        return head;
    }
};
```

### Complexity Analysis

* Time complexity: **O(sz)**.
* Space complexity: **O(1)**.
