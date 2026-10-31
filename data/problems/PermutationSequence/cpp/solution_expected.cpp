class Solution {
public:
    string getPermutation(int n, int k) {
        string digits;
        vector<int> factorial(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            digits += static_cast<char>('0' + i);
            factorial[i] = factorial[i - 1] * i;
        }
        --k;
        string result;
        for (int remaining = n; remaining > 0; --remaining) {
            const int index = k / factorial[remaining - 1];
            k %= factorial[remaining - 1];
            result += digits[index];
            digits.erase(digits.begin() + index);
        }
        return result;
    }
};