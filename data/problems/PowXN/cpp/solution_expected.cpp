class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;
        if (power < 0) {
            x = 1 / x;
            power = -power;
        }
        double result = 1.0;
        while (power) {
            if (power & 1) {
                result *= x;
            }
            x *= x;
            power >>= 1;
        }
        return result;
    }
};