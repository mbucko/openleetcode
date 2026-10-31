class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for (size_t i = 1; i < strs.size(); ++i) {
            size_t len = 0;
            while (len < prefix.size() && len < strs[i].size() && prefix[len] == strs[i][len]) {
                ++len;
            }
            prefix.resize(len);
        }
        return prefix;
    }
};