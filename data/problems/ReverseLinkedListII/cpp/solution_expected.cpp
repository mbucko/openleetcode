class Solution {
public:
    vector<int> reverseBetween(vector<int>& head, int left, int right) {
        reverse(head.begin() + left - 1, head.begin() + right);
        return head;
    }
};