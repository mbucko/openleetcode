### Approach

All words have length w, so a match always starts at some offset in 0..w-1 and moves in steps of w. For each offset, slide a window word by word, counting the words inside it. An unknown word resets the window. A word seen too often shrinks the window from the left until the counts are valid again. When the window holds every word, record its start.

### Implementation

```cpp
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
```

### Complexity Analysis

* Time complexity: **O(n * w)**.
* Space complexity: **O(m * w) for the word counts, where m is the number of words**.
