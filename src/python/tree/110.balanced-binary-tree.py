from typing import Optional
from lc_test_utils import TreeNode

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        def check(node):
            if not node:
                return 0
            
            l = check(node.left)
            r = check(node.right)
            
            if l == -1 or r == -1 or abs(l - r) > 1:
                return -1
            return 1 + max(l, r)
            
        return check(root) != -1
