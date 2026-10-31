class Solution {
public:
    vector<int> swapPairs(vector<int>& head) {
        for (size_t i = 0; i + 1 < head.size(); i += 2) {
            swap(head[i], head[i + 1]);
        }
        return head;
    }
};