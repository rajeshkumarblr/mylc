// lc_test_utils.cpp — Shared utility functions for list/tree operations.
// These are linked into each standalone solution binary.

#include "lc_test_utils.h"
#include <iostream>
#include <queue>
#include <vector>

template <class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
  os << "[";
  for (size_t i = 0; i < v.size(); ++i) {
    if (i)
      os << ",";
    os << v[i];
  }
  os << "]";
  return os;
}

ListNode *vec_to_list(const std::vector<int> &v) {
  ListNode dummy;
  ListNode *curr = &dummy;
  for (int x : v) {
    curr->next = new ListNode(x);
    curr = curr->next;
  }
  return dummy.next;
}

std::vector<int> list_to_vec(ListNode *head) {
  std::vector<int> v;
  while (head) {
    v.push_back(head->val);
    head = head->next;
  }
  return v;
}

void free_list(ListNode *head) {
  while (head) {
    ListNode *tmp = head;
    head = head->next;
    delete tmp;
  }
}

// Tree support functions.

TreeNode *
build_tree_from_level_order(const std::vector<std::optional<int>> &data) {
  if (data.empty() || !data[0].has_value())
    return nullptr;
  TreeNode *root = new TreeNode(data[0].value());
  std::queue<TreeNode *> q;
  q.push(root);
  size_t i = 1;
  while (!q.empty() && i < data.size()) {
    TreeNode *node = q.front();
    q.pop();
    if (i < data.size() && data[i].has_value()) {
      node->left = new TreeNode(data[i].value());
      q.push(node->left);
    }
    ++i;
    if (i < data.size() && data[i].has_value()) {
      node->right = new TreeNode(data[i].value());
      q.push(node->right);
    }
    ++i;
  }
  return root;
}

void free_tree(TreeNode *root) {
  if (!root)
    return;
  free_tree(root->left);
  free_tree(root->right);
  delete root;
}

TreeNode *vec_to_tree(const std::vector<int> &data) {
  if (data.empty())
    return nullptr;
  TreeNode *root = new TreeNode(data[0]);
  std::queue<TreeNode *> q;
  q.push(root);
  size_t i = 1;
  while (!q.empty() && i < data.size()) {
    TreeNode *node = q.front();
    q.pop();
    if (i < data.size() && data[i] != -1) { // Use -1 as null marker
      node->left = new TreeNode(data[i]);
      q.push(node->left);
    }
    i++;
    if (i < data.size() && data[i] != -1) {
      node->right = new TreeNode(data[i]);
      q.push(node->right);
    }
    i++;
  }
  return root;
}

std::vector<int> tree_to_vec(TreeNode *root) {
  if (!root)
    return {};
  std::vector<int> result;
  std::queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();
    if (node) {
      result.push_back(node->val);
      q.push(node->left);
      q.push(node->right);
    } else {
      result.push_back(-1); // Use -1 as null marker
    }
  }
  // Remove trailing nulls
  while (!result.empty() && result.back() == -1) {
    result.pop_back();
  }
  return result;
}
