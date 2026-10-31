from treenode import TreeNode


class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        stack = []
        node = root
        prev = None
        while node or stack:
            while node:
                stack.append(node)
                node = node.left
            node = stack.pop()
            if prev is not None and node.val <= prev:
                return False
            prev = node.val
            node = node.right
        return True
