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