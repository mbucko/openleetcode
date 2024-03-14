#ifndef TREENODE_H
#define TREENODE_H

#include <ostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}

  private:
    friend std::ostream& operator<< (std::ostream& os, TreeNode node);
    
    std::string toString() const;
};

inline std::ostream& operator<< (std::ostream& os, TreeNode node) {
    return os << node.toString();
}

#endif // TREENODE_H