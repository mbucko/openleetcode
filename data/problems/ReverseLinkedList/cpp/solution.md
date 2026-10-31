### Approach

Build a linked list from the input values. Walk it once with a pointer to the previous node: save the next node, point the current node back at the previous one, then move both pointers forward. When the walk ends, the previous pointer is the new head. Read the values from there into the output array.

### Implementation

```cpp
class Solution {
public:
    vector<int> reverseList(vector<int>& head) {
        struct ListNode {
            int val;
            ListNode* next;
        };
        vector<ListNode> nodes(head.size());
        for (int i = 0; i < head.size(); ++i) {
            nodes[i] = {head[i], i + 1 < head.size() ? &nodes[i + 1] : nullptr};
        }

        ListNode* prev = nullptr;
        ListNode* cur = head.empty() ? nullptr : &nodes[0];
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        vector<int> result;
        for (ListNode* node = prev; node; node = node->next) {
            result.push_back(node->val);
        }
        return result;
    }
};
```

### Complexity Analysis

* Time complexity: **O(n)**.
* Space complexity: **O(n) to build the list and the output; the reversal itself uses O(1) extra space**.
