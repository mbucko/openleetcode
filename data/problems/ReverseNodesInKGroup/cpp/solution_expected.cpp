class Solution {
public:
    vector<int> reverseKGroup(vector<int>& head, int k) {
        for (size_t start = 0; start + k <= head.size(); start += k) {
            reverse(head.begin() + start, head.begin() + start + k);
        }
        return head;
    }
};