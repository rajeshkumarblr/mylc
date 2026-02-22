
import os
import sys
import importlib.util
from typing import Dict, Any

import lc_test_utils

def load_solution(category: str, filename: str) -> Any:
    # Construct absolute path to the file
    # Assuming main.py is in src/python/
    base_dir = os.path.dirname(os.path.abspath(__file__))
    file_path = os.path.join(base_dir, category, filename)
    
    if not os.path.exists(file_path):
        return None
        
    spec = importlib.util.spec_from_file_location(filename, file_path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    
    return module.Solution()

def build_registry():
    registry = {}
    
    # helper to register
    def reg(pid, cat, fname, method_name):
        sol = load_solution(cat, fname)
        if sol:
            # Bind the method
            registry[pid] = getattr(sol, method_name)

    # Register problems here
    reg("1", "hash", "1.two-sum.py", "twoSum")
    reg("2", "list", "2.add-two-numbers.py", "addTwoNumbers")
    reg("3", "sliding_window", "3.longest-substring-without-repeating-characters.py", "lengthOfLongestSubstring")
    reg("9", "misc", "9.palindrome-number.py", "isPalindrome")
    reg("11", "two_pointer", "11.container-with-most-water.py", "maxArea")
    reg("15", "two_pointer", "15.3-sum.py", "threeSum")
    reg("20", "stack", "20.valid-parentheses.py", "isValid")
    reg("21", "list", "21.merge-two-sorted-lists.py", "mergeTwoLists")
    reg("33", "binary_search", "33.search-in-rotated-sorted-array.py", "search")
    reg("35", "binary_search", "35.search-insert-position.py", "searchInsert")
    reg("36", "hash", "36.valid-sudoku.py", "isValidSudoku")
    reg("42", "two_pointer", "42.trapping-rain-water.py", "trap")
    reg("70", "dp", "70.climbing-stairs.py", "climbStairs")
    reg("94", "tree", "94.binary-tree-inorder-traversal.py", "inorderTraversal")
    reg("98", "tree", "98.validate-binary-search-tree.py", "isValidBST")
    reg("100", "tree", "100.same-tree.py", "isSameTree")
    reg("102", "tree", "102.binary-tree-level-order-traversal.py", "levelOrder")
    reg("103", "tree", "103.binary-tree-zigzag-level-order-traversal.py", "zigzagLevelOrder")
    reg("104", "tree", "104.maximum-depth-of-binary-tree.py", "maxDepth")
    reg("110", "tree", "110.balanced-binary-tree.py", "isBalanced")
    reg("139", "dp", "139.word-break.py", "wordBreak")
    reg("160", "list", "160.intersection-of-two-linked-lists.py", "getIntersectionNode")
    reg("198", "dp", "198.house-robber.py", "rob")
    reg("200", "graphs", "200.number-of-islands.py", "numIslands")
    reg("206", "list", "206.reverse-linked-list.py", "reverseList")
    reg("213", "dp", "213.house-robber-ii.py", "rob")
    reg("226", "tree", "226.invert-binary-tree.py", "invertTree")
    reg("238", "prefix_sum", "238.product-of-array-except-self.py", "productExceptSelf")
    reg("424", "sliding_window", "424.longest-repeating-character-replacement.py", "characterReplacement")
    reg("438", "sliding_window", "438.find-all-anagrams-in-a-string.py", "findAnagrams")
    reg("560", "prefix_sum", "560.subarray-sum-equals-k.py", "subarraySum")
    reg("567", "sliding_window", "567.permutation-in-string.py", "checkInclusion")
    reg("739", "stack", "739.daily-temperatures.py", "dailyTemperatures")
    reg("1235", "dp", "1235.maximum-profit-in-job-scheduling.py", "jobScheduling")
    
    return registry

def main():
    category = os.environ.get("LC_CATEGORY")
    prob_num = os.environ.get("LC_PROB_NUM")
    
    registry = build_registry()
    lc_test_utils.run_tests(registry, prob_num, category)

if __name__ == "__main__":
    main()
