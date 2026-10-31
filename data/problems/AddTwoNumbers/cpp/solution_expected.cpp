class Solution {
public:
    vector<int> addTwoNumbers(vector<int>& l1, vector<int>& l2) {
        vector<int> result;
        int carry = 0;
        for (size_t i = 0; i < l1.size() || i < l2.size() || carry; ++i) {
            int total = carry;
            if (i < l1.size()) {
                total += l1[i];
            }
            if (i < l2.size()) {
                total += l2[i];
            }
            result.push_back(total % 10);
            carry = total / 10;
        }
        return result;
    }
};