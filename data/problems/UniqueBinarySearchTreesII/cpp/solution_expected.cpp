class Solution {
public:
    vector<vector<int>> generateTrees(int n) {
        vector<vector<int>> trees = build(1, n);
        sort(trees.begin(), trees.end());
        return trees;
    }

private:
    vector<vector<int>> build(int low, int high) {
        if (low > high) {
            return {{}};
        }
        vector<vector<int>> trees;
        for (int root = low; root <= high; ++root) {
            for (const auto& left : build(low, root - 1)) {
                for (const auto& right : build(root + 1, high)) {
                    vector<int> tree = {root};
                    tree.insert(tree.end(), left.begin(), left.end());
                    tree.insert(tree.end(), right.begin(), right.end());
                    trees.push_back(move(tree));
                }
            }
        }
        return trees;
    }
};