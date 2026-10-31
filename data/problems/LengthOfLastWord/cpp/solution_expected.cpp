class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while (s[i] == ' ') {
            --i;
        }
        int length = 0;
        while (i >= 0 && s[i] != ' ') {
            ++length;
            --i;
        }
        return length;
    }
};