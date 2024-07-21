#ifndef SINGLETREENODE_H
#define SINGLETREENODE_H

#include "treenode.h"

struct SingleTreeNode : public TreeNode {
    using TreeNode::TreeNode;
};

static_assert(sizeof(SingleTreeNode) == sizeof(TreeNode),
              "SingleTreeNode is not the same size as TreeNode");

#endif // SINGLETREENODE_H