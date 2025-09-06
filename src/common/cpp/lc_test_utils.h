#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <utility>
#include <ostream>
#include <sstream>
#include <iomanip>
#include <optional>
#include <queue>
#include <vector>
#include <iostream>
#include <iomanip>
using std::optional; using std::nullopt;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode) : val(x), left(leftNode), right(rightNode) {}
};

// lc_test_utils.h  (add near the top)
inline bool lc_silent() {
    static bool s = (std::getenv("LC_SILENT") != nullptr);
    return s;
}

// For vector output
template<typename T>
void print_vector(const std::vector<T>& v) {
    std::cout << "[";
    for (size_t i = 0; i < (int)v.size(); ++i) {
        std::cout << v[i];
        if (i + 1 < (int)v.size()) std::cout << ", ";
    }
    std::cout << "]";
}


// Overload operator<< for vector<T>
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i + 1 < v.size()) os << ",";
    }
    os << "]";
    return os;
}

// For Two Sum, where order of indices may not matter
template<typename Input, typename Output, typename Func>
bool run_vector_tests(const std::vector<std::pair<Input, Output>>& tests, Func func) {
    bool all_passed = true;
    for (const auto& [input, expected] : tests) {
        Output result = func(input);
        bool pass = (result == expected) ||
                    (result.size() == 2 && expected.size() == 2 &&
                     result[0] == expected[1] && result[1] == expected[0]);
        std::cout << "Input: ";
        print_vector(input.first);
        std::cout << ", target=" << input.second << " | ";
        if (pass) {
            std::cout << "PASS";
        } else {
            std::cout << "FAIL (got: ";
            print_vector(result);
            std::cout << "; expected: ";
            print_vector(expected);
            std::cout << ")";
            all_passed = false;
        }
        std::cout << std::endl;
    }
    return all_passed;
}

// Utility for testing int->bool functions
template<typename Func>
bool run_bool_tests(const std::vector<std::pair<int, bool>>& tests, Func func) {
    bool all_passed = true;
    for (const auto& [input, expected] : tests) {
        bool result = func(input);
        std::cout << "Input: " << input << " | Expected: " << expected << " | Got: " << result << " | ";
        if (result == expected) {
            std::cout << "PASS" << std::endl;
        } else {
            std::cout << "FAIL" << std::endl;
            all_passed = false;
        }
    }
    return all_passed;
}

// Print test result for any comparable type, with aligned columns
template<typename Input, typename Result>
bool print_test_result(const Input& input, const Result& result, const Result& expected) {
    bool res = (result == expected);
    if (!lc_silent()) {
        constexpr int input_width = 20;
        constexpr int expected_width = 15;
        constexpr int got_width = 15;

        std::ostringstream oss_input, oss_expected, oss_result;
        oss_input << input;
        oss_expected << expected;
        oss_result << result;

        std::cout << std::left
                << "Input: " << std::setw(input_width) << oss_input.str()
                << " | Expected: " << std::setw(expected_width) << oss_expected.str()
                << " | Got: " << std::setw(got_width) << oss_result.str()
                << " | ";
        std::cout << (res ? "PASS" : "FAIL") << std::endl;
    }
    return res;
}

// Build a binary tree from level-order like [1,null,2,3]
inline TreeNode* buildTree(const std::vector<std::optional<int>>& lvl) {
    if (lvl.empty() || !lvl[0].has_value()) return nullptr;
    TreeNode* root = new TreeNode(*lvl[0]);
    std::queue<TreeNode*> q; q.push(root);
    size_t i = 1;
    while (!q.empty() && i < lvl.size()) {
        TreeNode* cur = q.front(); q.pop();
        if (i < lvl.size() && lvl[i].has_value()) {
            cur->left = new TreeNode(*lvl[i]);
            q.push(cur->left);
        }
        ++i;
        if (i < lvl.size() && lvl[i].has_value()) {
            cur->right = new TreeNode(*lvl[i]);
            q.push(cur->right);
        }
        ++i;
    }
    return root;
}

inline void freeTree(TreeNode* n) {
    if (!n) return;
    freeTree(n->left);
    freeTree(n->right);
    delete n;
}

// Pretty print a vector of optional<int> as a tree input
inline std::string tree_input_str(const std::vector<std::optional<int>>& input) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i].has_value()) oss << input[i].value();
        else oss << "null";
        if (i + 1 < input.size()) oss << ",";
    }
    oss << "]";
    return oss.str();
}

// Generic tree test runner for functions returning vector<int>
template<typename Func>
bool run_tree_tests(const std::vector<std::pair<std::vector<std::optional<int>>, std::vector<int>>>& test_cases, Func func) {
    constexpr int input_width = 25;
    constexpr int expected_width = 15;
    constexpr int got_width = 15;
    bool all_passed = true;
    for (size_t i = 0; i < test_cases.size(); ++i) {
        TreeNode* root = buildTree(test_cases[i].first);
        auto result = func(root);
        std::ostringstream oss_input, oss_expected, oss_result;
        oss_input << tree_input_str(test_cases[i].first);
        oss_expected << result;
        oss_result << test_cases[i].second;
        std::cout << std::left
                  << "Input: " << std::setw(input_width) << oss_input.str()
                  << " | Expected: " << std::setw(expected_width) << test_cases[i].second
                  << " | Got: " << std::setw(got_width) << result
                  << " | " << ((result == test_cases[i].second) ? "PASS" : "FAIL") << std::endl;
        all_passed &= (result == test_cases[i].second);
        freeTree(root);
    }
    return all_passed;
}
