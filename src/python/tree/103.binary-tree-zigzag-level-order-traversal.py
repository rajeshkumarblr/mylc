from typing import List, Optional
from lc_test_utils import TreeNode

class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        res = []
        q = [root]
        left_to_right = True
        while q:
            level = []
            for _ in range(len(q)):
                node = q.pop(0)
                level.append(node.val)
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)
            
            if not left_to_right:
                level.reverse()
            res.append(level)
            left_to_right = not left_to_right
        return res
