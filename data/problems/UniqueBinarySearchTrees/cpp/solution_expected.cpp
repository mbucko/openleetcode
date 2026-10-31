class Solution {
public:
    int numTrees(int n) {
        vector<long long> count(n + 1, 0);
        count[0] = 1;
        count[1] = 1;
        for (int size = 2; size <= n; ++size) {
            for (int root = 1; root <= size; ++root) {
                count[size] += count[root - 1] * count[size - root];
            }
        }
        return static_cast<int>(count[n]);
    }
};