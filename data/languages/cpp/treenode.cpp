#include "treenode.h"

#include "printer.h"

std::string TreeNode::toString() const {
    return Printer::toString(this);
}