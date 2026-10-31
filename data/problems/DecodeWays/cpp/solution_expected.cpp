class Solution {
public:
    int numDecodings(string s) {
        long long prev = 1;
        long long cur = s[0] != '0' ? 1 : 0;
        for (size_t i = 1; i < s.size(); ++i) {
            long long next = 0;
            if (s[i] != '0') {
                next += cur;
            }
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                next += prev;
            }
            prev = cur;
            cur = next;
        }
        return static_cast<int>(cur);
    }
};