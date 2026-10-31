class Solution {
public:
    vector<int> deleteDuplicates(vector<int>& head) {
        vector<int> result;
        for (size_t i = 0; i < head.size();) {
            size_t j = i;
            while (j < head.size() && head[j] == head[i]) {
                ++j;
            }
            if (j - i == 1) {
                result.push_back(head[i]);
            }
            i = j;
        }
        return result;
    }
};