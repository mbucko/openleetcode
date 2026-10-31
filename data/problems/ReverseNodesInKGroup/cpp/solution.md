### Approach

Step through the list one group of k nodes at a time, and stop when fewer than k nodes remain. Reverse each full group in place. With real nodes, that means reversing the group's links and attaching the reversed group to the previous group and to the rest of the list.

### Implementation

```cpp
class Solution {
public:
    vector<int> reverseKGroup(vector<int>& head, int k) {
        for (size_t start = 0; start + k <= head.size(); start += k) {
            reverse(head.begin() + start, head.begin() + start + k);
        }
        return head;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
