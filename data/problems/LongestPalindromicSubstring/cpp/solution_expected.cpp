class Solution {
public:
    string longestPalindrome(string s) {
        int bestStart = 0;
        int bestLen = 0;
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                --left;
                ++right;
            }
            if (right - left - 1 > bestLen) {
                bestStart = left + 1;
                bestLen = right - left - 1;
            }
        };
        for (int i = 0; i < s.size(); ++i) {
            expand(i, i);
            expand(i, i + 1);
        }
        return s.substr(bestStart, bestLen);
    }
};