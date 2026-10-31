class Solution {
public:
    int mySqrt(int x) {
        long long low = 0;
        long long high = x;
        while (low < high) {
            const long long mid = (low + high + 1) / 2;
            if (mid * mid <= x) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return static_cast<int>(low);
    }
};