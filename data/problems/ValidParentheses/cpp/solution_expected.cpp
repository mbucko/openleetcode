class Solution {
public:
    bool isValid(string s) {
        const unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
        vector<char> stack;
        for (const char ch : s) {
            const auto it = pairs.find(ch);
            if (it != pairs.end()) {
                if (stack.empty() || stack.back() != it->second) {
                    return false;
                }
                stack.pop_back();
            } else {
                stack.push_back(ch);
            }
        }
        return stack.empty();
    }
};