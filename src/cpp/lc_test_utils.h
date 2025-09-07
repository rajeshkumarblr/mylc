#pragma once

#include <algorithm>
#include <chrono>
#include <cctype>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <optional>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <optional>

// --------------------------
// Env + small conveniences
// --------------------------
inline bool lc_silent() {
    const char* s = std::getenv("LC_SILENT");
    // silent iff LC_SILENT is set and not "0"/empty
    return s && s[0] != '\0' && s[0] != '0';
}

#define LC_DUMP(x) do { if (!lc_silent()) std::cout << #x << " = " << (x) << "\n"; } while(0)

inline uint64_t lc_nanos() {
    using namespace std::chrono;
    return duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count();
}
inline double lc_millis_since(uint64_t start_ns) {
    return static_cast<double>(lc_nanos() - start_ns) / 1e6;  // fix -Wconversion
}

// ------------------------------------
// ostream helpers (pretty-print stuff)
// ------------------------------------
template <typename T>
inline std::ostream& operator<<(std::ostream& os, const std::optional<T>& o) {
    if (o) os << *o; else os << "null";
    return os;
}

// join range helper
template <class It>
inline void __join_iter(std::ostream& os, It first, It last, const char* sep = ",") {
    bool first_elem = true;
    for (; first != last; ++first) {
        if (!first_elem) os << sep;
        first_elem = false;
        os << *first;
    }
}

// NOTE: Define container printers FIRST so they're visible when pair/optional need them.

// sequences
template <class T>
inline std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    __join_iter(os, v.begin(), v.end());
    os << "]";
    return os;
}
template <class T>
inline std::ostream& operator<<(std::ostream& os, const std::deque<T>& v) {
    os << "[";
    __join_iter(os, v.begin(), v.end());
    os << "]";
    return os;
}
template <class T>
inline std::ostream& operator<<(std::ostream& os, const std::list<T>& v) {
    os << "[";
    __join_iter(os, v.begin(), v.end());
    os << "]";
    return os;
}

// sets
template <class T, class Cmp, class Alloc>
inline std::ostream& operator<<(std::ostream& os, const std::set<T,Cmp,Alloc>& s) {
    os << "{";
    __join_iter(os, s.begin(), s.end());
    os << "}";
    return os;
}
template <class T, class Hash, class Eq, class Alloc>
inline std::ostream& operator<<(std::ostream& os, const std::unordered_set<T,Hash,Eq,Alloc>& s) {
    os << "{";
    bool first = true;
    for (auto&& x : s) { if (!first) os << ","; first = false; os << x; }
    os << "}";
    return os;
}

// maps
template <class K, class V, class Cmp, class Alloc>
inline std::ostream& operator<<(std::ostream& os, const std::map<K,V,Cmp,Alloc>& m) {
    os << "{";
    bool first = true;
    for (auto&& kv : m) { if (!first) os << ","; first = false; os << kv.first << ":" << kv.second; }
    os << "}";
    return os;
}
template <class K, class V, class Hash, class Eq, class Alloc>
inline std::ostream& operator<<(std::ostream& os, const std::unordered_map<K,V,Hash,Eq,Alloc>& m) {
    os << "{";
    bool first = true;
    for (auto&& kv : m) { if (!first) os << ","; first = false; os << kv.first << ":" << kv.second; }
    os << "}";
    return os;
}

// pair AFTER containers
template <class A, class B>
inline std::ostream& operator<<(std::ostream& os, const std::pair<A,B>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

// -----------------
// Tree definitions
// -----------------

// Local tree node. Safe because your LeetCode submission excludes this header.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

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

// Pretty print a vector<optional<int>> as a tree input like "[1,null,2,3]"
inline std::string tree_input_str(const std::vector<std::optional<int>>& input) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i].has_value()) oss << *input[i]; else oss << "null";
        if (i + 1 < input.size()) oss << ",";
    }
    oss << "]";
    return oss.str();
}

// Handy inorder traversal -> vector<int>
inline std::vector<int> inorder_vec(TreeNode* r) {
    std::vector<int> out;
    std::vector<TreeNode*> st;
    TreeNode* cur = r;
    while (cur || !st.empty()) {
        if (cur) { st.push_back(cur); cur = cur->left; }
        else { cur = st.back(); st.pop_back(); out.push_back(cur->val); cur = cur->right; }
    }
    return out;
}

// ------------------------
// Printing & test helpers
// ------------------------

template<typename T>
inline void print_vector(const std::vector<T>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i + 1 < v.size()) std::cout << ", ";
    }
    std::cout << "]";
}

template<typename Input, typename Result>
inline bool print_test_result(const Input& input, const Result& result, const Result& expected) {
    bool ok = (result == expected);
    if (!lc_silent()) {
        constexpr int input_width = 26;
        constexpr int expected_width = 18;
        constexpr int got_width = 18;

        std::ostringstream a, b, c;
        a << input; b << expected; c << result;

        std::cout << std::left
                  << "Input: "   << std::setw(input_width)    << a.str()
                  << " | Expect: "<< std::setw(expected_width) << b.str()
                  << " | Got: "  << std::setw(got_width)      << c.str()
                  << " | " << (ok ? "PASS" : "FAIL") << "\n";
    }
    return ok;
}

// Generic runner: cases of (Input -> Output)
template <typename Input, typename Output, typename F>
inline bool run_cases(const std::vector<std::pair<Input, Output>>& cases, F func) {
    bool all = true;
    for (auto&& [in, exp] : cases) {
        auto got = func(in);
        all &= print_test_result(in, got, exp);
    }
    return all;
}

// Tree-specific runner: (TreeNode* -> Output)
template<typename Output, typename F>
inline bool run_tree_tests(const std::vector<std::pair<std::vector<std::optional<int>>, Output>>& test_cases, F func) {
    bool all_passed = true;
    for (const auto& [lvl, expected] : test_cases) {
        TreeNode* root = buildTree(lvl);
        auto result = func(root);
        all_passed &= print_test_result(tree_input_str(lvl), result, expected);
        freeTree(root);
    }
    return all_passed;
}

// ------------------------
// Singly linked-list helpers (generic)
// ------------------------

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *nextNode) : val(x), next(nextNode) {}
};

// Build a list from vector<int>
template <typename Node>
inline Node* make_list(const std::vector<int>& vals) {
    Node dummy;
    Node* cur = &dummy;
    for (int v : vals) {
        cur->next = new Node(v);
        cur = cur->next;
    }
    return dummy.next;
}

// Convert list -> vector<int>
template <typename Node>
inline std::vector<int> list_to_vector(Node* node) {
    std::vector<int> out;
    while (node) {
        out.push_back(node->val);
        node = node->next;
    }
    return out;
}

// Free entire list
template <typename Node>
inline void free_list(Node* node) {
    while (node) {
        Node* t = node;
        node = node->next;
        delete t;
    }
}

// Pretty printer for singly linked lists (generic Node with val/next)
template <typename Node>
struct list_view { Node* head; size_t cap; };

template <typename Node>
inline list_view<Node> as_list(Node* head, size_t cap = 64) { return {head, cap}; }

template <typename Node>
inline std::ostream& operator<<(std::ostream& os, list_view<Node> v) {
    os << "[";
    size_t i = 0;
    for (Node* p = v.head; p && i < v.cap; p = p->next, ++i) {
        if (i) os << ", ";
        os << p->val;
    }
    if (v.head && i == v.cap) os << ", ...";
    os << "]";
    return os;
}

template <typename Node, typename F>
inline bool run_ll_cases(
    const std::vector<std::pair<std::pair<std::vector<int>, std::vector<int>>, std::vector<int>>>& cases,
    F func,
    bool reuse_inputs = false)
{
    bool all = true;
    for (auto&& [in, expected] : cases) {
        Node* l1 = make_list<Node>(in.first);
        Node* l2 = make_list<Node>(in.second);
        Node* r  = func(l1, l2);

        auto got = list_to_vector<Node>(r);
        all &= print_test_result(std::make_pair(in.first, in.second), got, expected);

        if (reuse_inputs) {
            free_list<Node>(r);       // r owns nodes (relinked from l1/l2)
        } else {
            free_list<Node>(l1);
            free_list<Node>(l2);
            free_list<Node>(r);
        }
    }
    return all;
}

// Run cases for functions F: (const Vec&) -> Out  OR (Vec&) -> Out
// If F requires Vec&, we pass a copy so inputs are never mutated.
template <typename Vec, typename Out, typename F>
inline bool run_vec_cases(const std::vector<std::pair<Vec, Out>>& cases, F func, int iters = 1) {
    bool all = true;
    const uint64_t t0 = lc_nanos();

    for (int rep = 0; rep < iters; ++rep) {
        for (const auto& [in, expected] : cases) {
            if constexpr (std::is_invocable_v<F, const Vec&>) {
                Out got = func(in);
                all &= print_test_result(in, got, expected);
            } else if constexpr (std::is_invocable_v<F, Vec&>) {
                Vec tmp = in;                 // copy for mutating signature
                Out got = func(tmp);
                all &= print_test_result(in, got, expected);
            } else {
                static_assert(sizeof(F) == 0, "func must accept (const Vec&) or (Vec&)");
            }
        }
    }

    if (!lc_silent()) {
        const double ms = lc_millis_since(t0);
        std::cout << "Ran " << (cases.size() * static_cast<size_t>(iters))
                  << " vectors in " << std::fixed << std::setprecision(3) << ms << " ms\n";
    }
    return all;
}

inline int lc_env_iters(const char* name = "LC_STRESS_ITERS", int def = 1) {
    if (const char* s = std::getenv(name)) { int v = std::atoi(s); return v > 0 ? v : def; }
    return def;
}
