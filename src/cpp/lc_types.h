#pragma once
#include <vector>

// Sentinel value for null tree nodes (matches vec_to_tree convention)
constexpr int None = -1;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *nextNode) : val(x), next(nextNode) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Test helper declarations defined in lc_test_utils.cpp
ListNode *vec_to_list(const std::vector<int> &v);
std::vector<int> list_to_vec(ListNode *head);
void free_list(ListNode *head);

TreeNode *vec_to_tree(const std::vector<int> &v);
std::vector<int> tree_to_vec(TreeNode *root);
void free_tree(TreeNode *root);