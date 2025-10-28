#include <vector>
#include <stack>
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <optional>
#include "lc_types.h"

using json  = nlohmann::json;

// Problem 9: Palindrome Number
bool isPalindrome(int x);
bool lc_test_9(const json& j);


// ===== Print helpers (minimal) =====
template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v);


// Problem 1: Two Sum
std::vector<int> twoSum(std::vector<int>& nums, int target);
bool lc_test_1(const json& j);


// Problem 2: Add Two Numbers
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
bool lc_test_2(const json& j);

// Problem 3: Longest Substring Without Repeating Characters
int lengthOfLongestSubstring(std::string s);
bool lc_test_3(const json& j);

int maxArea(std::vector<int>& height);
bool lc_test_11(const json& j);

// Problem 15: 3Sum
std::vector<std::vector<int>> threeSum(std::vector<int>& nums);
bool lc_test_15(const json& j);

// Helper to create a linked list from a vector
ListNode* vec_to_list(const std::vector<int>& v);
// Helper to convert a linked list to a vector
std::vector<int> list_to_vec(ListNode* head);
// Helper to free a linked list
void free_list(ListNode* head);

// Problem 21: Merge Two Sorted Lists
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
bool lc_test_21(const json& j);

int trap(std::vector<int>& height);
bool lc_test_42(const json& j);

std::vector<int> inorderTraversal(TreeNode* root);
bool lc_test_94(const json& j);
// Problem 11: Container With Most Water

// Problem 98: Validate BST
bool isValidBST(TreeNode* root);
bool lc_test_98(const json& j);

int maxDepth(TreeNode* root);
bool lc_test_104(const json& j);

bool isBalanced(TreeNode* root);
bool lc_test_110(const json& j);

int characterReplacement(std::string s, int k);
bool lc_test_424(const json& j);

std::vector<int> findAnagrams(std::string s, std::string p);
bool lc_test_438(const json& j);

bool checkInclusion(std::string s1, std::string s2);
bool lc_test_567(const json& j);

std::vector<std::vector<int>> levelOrder(TreeNode* root);
bool lc_test_102(const json& j);

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root);
bool lc_test_103(const json& j);
// Problem 100: Same Tree
bool isSameTree(TreeNode* p, TreeNode* q);
bool lc_test_100(const json& j);
std::string get_testcases_json_path();

// Problem 20: Valid Parentheses
bool isValid(std::string s);
bool lc_test_20(const json& j);

// Problem 739: Daily Temperatures
std::vector<int> dailyTemperatures(std::vector<int> temperatures);
bool lc_test_739(const json& j);

// Problem 35: Search Insert Position
int searchInsert(std::vector<int>& nums, int target);
bool lc_test_35(const json& j);

// Problem 36: Valid Sudoku
bool isValidSudoku(std::vector<std::vector<char>>& board);
bool lc_test_36(const json& j);

// Problem 160: Intersection of Two Linked Lists
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);
bool lc_test_160(const json& j);

// Problem 200: Number of Islands
int numIslands(std::vector<std::vector<char>>& grid);
bool lc_test_200(const json& j);

// Problem 206: Reverse Linked List
ListNode* reverseList(ListNode* head);
bool lc_test_206(const json& j);

// Problem 226: Invert Binary Tree
TreeNode* invertTree(TreeNode* root);
bool lc_test_226(const json& j);

// Problem 238: Product of Array Except Self
std::vector<int> productExceptSelf(std::vector<int>& nums);
bool lc_test_238(const json& j);

// Problem 560: Subarray Sum Equals K
int subarraySum(std::vector<int>& nums, int k);
bool lc_test_560(const json& j);

// Helper functions for tree conversion
TreeNode* vec_to_tree(const std::vector<int>& data);
std::vector<int> tree_to_vec(TreeNode* root);