### Approach

Rotating by the list's length gives back the same list, so first reduce k modulo the length. The last k nodes then move to the front. With real nodes: link the tail to the head to form a ring, walk to the new tail (length - k - 1 steps from the head), and break the ring after it.

### Implementation

```cpp
class Solution {
public:
    vector<int> rotateRight(vector<int>& head, int k) {
        if (head.empty()) {
            return head;
        }
        k %= head.size();
        rotate(head.begin(), head.end() - k, head.end());
        return head;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(1)**.
