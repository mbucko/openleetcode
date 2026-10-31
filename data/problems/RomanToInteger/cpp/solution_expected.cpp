class Solution {
public:
    int romanToInt(string s) {
        const unordered_map<char, int> values = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}};
        int total = 0;
        for (int i = 0; i < s.size(); ++i) {
            const int value = values.at(s[i]);
            if (i + 1 < s.size() && value < values.at(s[i + 1])) {
                total -= value;
            } else {
                total += value;
            }
        }
        return total;
    }
};