class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        const vector<string> keypad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result = {""};
        for (const char digit : digits) {
            vector<string> next;
            for (const string& prefix : result) {
                for (const char letter : keypad[digit - '0']) {
                    next.push_back(prefix + letter);
                }
            }
            result = move(next);
        }
        return result;
    }
};