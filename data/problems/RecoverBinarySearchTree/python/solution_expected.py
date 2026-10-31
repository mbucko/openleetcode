from typing import List
from treenode import TreeNode


class Solution:
    def recoverTree(self, root: TreeNode) -> List[int]:
        first = second = prev = None
        stack = []
        node = root
        while node or stack:
            while node:
                stack.append(node)
                node = node.left
            node = stack.pop()
            if prev is not None and node.val < prev.val:
                if first is None:
                    first = prev
                second = node
            prev = node
            node = node.right
        return sorted([first.val, second.val])
