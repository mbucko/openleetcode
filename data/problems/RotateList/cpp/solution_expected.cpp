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