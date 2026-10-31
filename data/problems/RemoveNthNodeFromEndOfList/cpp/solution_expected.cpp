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