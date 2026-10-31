class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= static_cast<int>(s.size())) {
            return s;
        }
        vector<string> rows(numRows);
        int row = 0;
        int step = 1;
        for (const char ch : s) {
            rows[row] += ch;
            if (row == 0) {
                step = 1;
            } else if (row == numRows - 1) {
                step = -1;
            }
            row += step;
        }
        string result;
        for (const string& r : rows) {
            result += r;
        }
        return result;
    }
};