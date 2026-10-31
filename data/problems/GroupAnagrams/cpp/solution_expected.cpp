class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const string& word : strs) {
            string key = word;
            sort(key.begin(), key.end());
            groups[key].push_back(word);
        }
        vector<vector<string>> result;
        for (auto& [key, group] : groups) {
            sort(group.begin(), group.end());
            result.push_back(move(group));
        }
        sort(result.begin(), result.end());
        return result;
    }
};