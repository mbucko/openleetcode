class Solution {
public:
    string countAndSay(int n) {
        string term = "1";
        for (int step = 1; step < n; ++step) {
            string next;
            for (size_t i = 0; i < term.size();) {
                size_t j = i;
                while (j < term.size() && term[j] == term[i]) {
                    ++j;
                }
                next += to_string(j - i) + term[i];
                i = j;
            }
            term = move(next);
        }
        return term;
    }
};