class Solution {
public:
    string minWindow(string s, string t) {
        int need[128] = {0};
        for (const char ch : t) {
            ++need[static_cast<unsigned char>(ch)];
        }
        int missing = t.size();
        int bestStart = 0;
        int bestLen = INT_MAX;
        int left = 0;
        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            if (need[static_cast<unsigned char>(s[right])]-- > 0) {
                --missing;
            }
            while (missing == 0) {
                if (right - left + 1 < bestLen) {
                    bestStart = left;
                    bestLen = right - left + 1;
                }
                if (++need[static_cast<unsigned char>(s[left])] > 0) {
                    ++missing;
                }
                ++left;
            }
        }
        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};