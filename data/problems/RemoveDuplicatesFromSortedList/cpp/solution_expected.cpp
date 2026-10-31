class Solution {
public:
    vector<int> deleteDuplicates(vector<int>& head) {
        vector<int> result;
        for (const int value : head) {
            if (result.empty() || result.back() != value) {
                result.push_back(value);
            }
        }
        return result;
    }
};