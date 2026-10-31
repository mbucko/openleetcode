class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        build(n, 0, 0, current, result);
        return result;
    }

private:
    void build(int n, int opened, int closed, string& current, vector<string>& result) {
        if (static_cast<int>(current.size()) == 2 * n) {
            result.push_back(current);
            return;
        }
        if (opened < n) {
            current.push_back('(');
            build(n, opened + 1, closed, current, result);
            current.pop_back();
        }
        if (closed < opened) {
            current.push_back(')');
            build(n, opened, closed + 1, current, result);
            current.pop_back();
        }
    }
};