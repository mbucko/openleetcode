class Solution {
public:
    vector<int> partition(vector<int>& head, int x) {
        vector<int> before;
        vector<int> after;
        for (const int value : head) {
            (value < x ? before : after).push_back(value);
        }
        before.insert(before.end(), after.begin(), after.end());
        return before;
    }
};