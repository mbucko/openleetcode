class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        const int wordLen = words[0].size();
        const int wordCount = words.size();
        unordered_map<string, int> need;
        for (const string& word : words) {
            ++need[word];
        }
        vector<int> result;
        for (int offset = 0; offset < wordLen; ++offset) {
            unordered_map<string, int> seen;
            int left = offset;
            int count = 0;
            for (int right = offset; right + wordLen <= static_cast<int>(s.size()); right += wordLen) {
                const string word = s.substr(right, wordLen);
                if (!need.count(word)) {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }
                ++seen[word];
                ++count;
                while (seen[word] > need[word]) {
                    --seen[s.substr(left, wordLen)];
                    --count;
                    left += wordLen;
                }
                if (count == wordCount) {
                    result.push_back(left);
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};