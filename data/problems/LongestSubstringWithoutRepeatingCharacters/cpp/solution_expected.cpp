class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.length();
        int maxLength = 0;
        unordered_map<char, int> lastVisited;

        for (int j = 0, i = 0; j < size; j++){
            if(lastVisited[s[j]] > 0) {
                i = max(lastVisited[s[j]], i);
            }
            maxLength = max(maxLength, j - i + 1);
            lastVisited[s[j]] = j + 1;
        }
        return maxLength;
    }
};