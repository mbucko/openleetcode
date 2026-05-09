from collections import deque

from treenode import TreeNode


class Solution:
    def isCompleteTree(self, root: TreeNode) -> bool:
        queue = deque([root])
        found_null = False

        while queue:
            node = queue.popleft()

            if node is None:
                found_null = True
                continue

            if found_null:
                return False

            queue.append(node.left)
            queue.append(node.right)

        return True
