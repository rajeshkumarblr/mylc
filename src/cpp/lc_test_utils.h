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
