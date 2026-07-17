// lc_test_utils.h — Shared utility declarations for list/tree operations.
#pragma once

#include "lc_types.h"
#include <iostream>
#include <optional>
#include <vector>

// ===== Print helpers =====
template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v);

// ===== List helpers =====
ListNode *vec_to_list(const std::vector<int> &v);
std::vector<int> list_to_vec(ListNode *head);
void free_list(ListNode *head);

// ===== Tree helpers =====
TreeNode *build_tree_from_level_order(const std::vector<std::optional<int>> &data);
TreeNode *vec_to_tree(const std::vector<int> &data);
std::vector<int> tree_to_vec(TreeNode *root);
void free_tree(TreeNode *root);