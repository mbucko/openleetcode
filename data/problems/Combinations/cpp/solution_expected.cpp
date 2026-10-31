class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        build(1, n, k, current, result);
        return result;
    }

private:
    void build(int start, int n, int k, vector<int>& current, vector<vector<int>>& result) {
        if (static_cast<int>(current.size()) == k) {
            result.push_back(current);
            return;
        }
        const int last = n - (k - static_cast<int>(current.size())) + 1;
        for (int value = start; value <= last; ++value) {
            current.push_back(value);
            build(value + 1, n, k, current, result);
            current.pop_back();
        }
    }
};