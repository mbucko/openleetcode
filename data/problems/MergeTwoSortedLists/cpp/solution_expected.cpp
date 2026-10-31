class Solution {
public:
    vector<int> mergeTwoLists(vector<int>& list1, vector<int>& list2) {
        vector<int> merged;
        size_t i = 0;
        size_t j = 0;
        while (i < list1.size() && j < list2.size()) {
            if (list1[i] <= list2[j]) {
                merged.push_back(list1[i++]);
            } else {
                merged.push_back(list2[j++]);
            }
        }
        merged.insert(merged.end(), list1.begin() + i, list1.end());
        merged.insert(merged.end(), list2.begin() + j, list2.end());
        return merged;
    }
};