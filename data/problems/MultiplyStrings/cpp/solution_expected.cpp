class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> digits(num1.size() + num2.size(), 0);
        for (int i = num1.size() - 1; i >= 0; --i) {
            for (int j = num2.size() - 1; j >= 0; --j) {
                const int total = digits[i + j + 1] + (num1[i] - '0') * (num2[j] - '0');
                digits[i + j + 1] = total % 10;
                digits[i + j] += total / 10;
            }
        }
        string result;
        for (const int d : digits) {
            if (!(result.empty() && d == 0)) {
                result += static_cast<char>('0' + d);
            }
        }
        return result.empty() ? "0" : result;
    }
};