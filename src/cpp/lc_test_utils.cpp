#include <cstdlib>
#include <vector>
#include <queue>
#include <iostream>
#include <nlohmann/json.hpp>
#include <optional>
#include "lc_test_utils.h"

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) os << ",";
        os << v[i];
    }
    os << "]";
    return os;
}

ListNode* vec_to_list(const std::vector<int>& v) {
    ListNode dummy;
    ListNode* curr = &dummy;
    for (int x : v) {
        curr->next = new ListNode(x);
        curr = curr->next;
    }
    return dummy.next;
}

std::vector<int> list_to_vec(ListNode* head) {
    std::vector<int> v;
    while (head) {
        v.push_back(head->val);
        head = head->next;
    }
    return v;
}

void free_list(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

// Tree support functions.

TreeNode* build_tree_from_level_order(const std::vector<std::optional<int>>& data) {
    if (data.empty() || !data[0].has_value()) return nullptr;
    TreeNode* root = new TreeNode(data[0].value());
    std::queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;
    while (!q.empty() && i < data.size()) {
        TreeNode* node = q.front(); q.pop();
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

void free_tree(TreeNode* root) {
    if (!root) return;
    free_tree(root->left);
    free_tree(root->right);
    delete root;
}

bool lc_test_1(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::vector<int> nums    = tc.at("input").get<std::vector<int>>();
        int target               = tc.at("target").get<int>();
        std::vector<int> expect  = tc.at("expected").get<std::vector<int>>();
        auto got = twoSum(nums, target);
        auto norm = [](std::vector<int> v){
            if (v.size()==2 && v[0]>v[1]) std::swap(v[0], v[1]);
            return v;
        };
        got = norm(got);
        expect = norm(expect);
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << got << " expected=" << expect << "\n";
        } else {
            ++idx;
        }
        all &= ok;
    }
    return all;
}

bool lc_test_2(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::vector<int> v1 = tc.at("l1").get<std::vector<int>>();
        std::vector<int> v2 = tc.at("l2").get<std::vector<int>>();
        std::vector<int> expect = tc.at("expected").get<std::vector<int>>();
        ListNode* l1 = nullptr;
        ListNode* l2 = nullptr;
        ListNode dummy;
        ListNode* tail = &dummy;
        for (int x : v1) { tail->next = new ListNode(x); tail = tail->next; }
        l1 = dummy.next;
        dummy.next = nullptr; tail = &dummy;
        for (int x : v2) { tail->next = new ListNode(x); tail = tail->next; }
        l2 = dummy.next;
        auto got_head = addTwoNumbers(l1, l2);
        std::vector<int> got;
        for (ListNode* p = got_head; p; p = p->next) got.push_back(p->val);
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << got << " expected=" << expect << "\n";
        } else {
            ++idx;
        }
        // Free all nodes
        while (got_head) { ListNode* tmp = got_head; got_head = got_head->next; delete tmp; }
        while (l1) { ListNode* tmp = l1; l1 = l1->next; delete tmp; }
        while (l2) { ListNode* tmp = l2; l2 = l2->next; delete tmp; }
        all &= ok;
    }
    return all;
}

bool lc_test_3(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::string s = tc.at("input").get<std::string>();
        int expect = tc.at("expected").get<int>();
        int got = lengthOfLongestSubstring(s);
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << got << " expected=" << expect << "\n";
        } else {
            ++idx;
        }
        all &= ok;
    }
    return all;
}


// Problem 9: Palindrome Number

// Implementations for lc_test_X functions (remove 'inline' and move bodies here)
bool lc_test_9(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        int input = tc.at("input").get<int>();
        bool expect = tc.at("expected").get<bool>();
        bool got = isPalindrome(input);
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << (got ? "true" : "false") << " expected=" << (expect ? "true" : "false") << "\n";
        } else {
            ++idx;
        }
        all &= ok;
    }
    return all;
}

bool lc_test_11(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::vector<int> input = tc.at("input").get<std::vector<int>>();
        int expect = tc.at("expected").get<int>();
        int got = maxArea(input);
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << got << " expected=" << expect << "\n";
        } else {
            ++idx;
        }
        all &= ok;
    }
    return all;
}

bool lc_test_21(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::vector<int> v1 = tc.at("l1").get<std::vector<int>>();
        std::vector<int> v2 = tc.at("l2").get<std::vector<int>>();
        std::vector<int> expect = tc.at("expected").get<std::vector<int>>();
        ListNode* l1 = vec_to_list(v1);
        ListNode* l2 = vec_to_list(v2);
        ListNode* got_head = mergeTwoLists(l1, l2);
        std::vector<int> got = list_to_vec(got_head);
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << got << " expected=" << expect << "\n";
        } else {
            ++idx;
        }
        free_list(got_head);
        all &= ok;
    }
    return all;
}

bool lc_test_15(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::vector<int> nums = tc.at("nums").get<std::vector<int>>();
        std::vector<std::vector<int>> expect = tc.at("expected").get<std::vector<std::vector<int>>>();
        std::vector<std::vector<int>> got = threeSum(nums);
        
        // Sort both expected and got to compare properly (since order may vary)
        std::sort(expect.begin(), expect.end());
        std::sort(got.begin(), got.end());
        
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL" << std::endl;
        } else {
            ++idx;
        }
        all &= ok;
    }
    return all;
}

bool lc_test_42(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::vector<int> input = tc.at("input").get<std::vector<int>>();
        int expect = tc.at("expected").get<int>();
        int got = trap(input); // Assuming maxArea is the solution for 42
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << got << " expected=" << expect << "\n";
        } else {
            ++idx;
        }
        all &= ok;
    }
    return all;
}

bool lc_test_94(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::vector<std::optional<int>> tree;
        for (const auto& val : tc.at("tree")) {
            if (val.is_null()) tree.push_back(std::nullopt);
            else tree.push_back(val.get<int>());
        }
        std::vector<int> expect = tc.at("expected").get<std::vector<int>>();
        TreeNode* root = build_tree_from_level_order(tree); // You must implement this helper if not present
        std::vector<int> got = inorderTraversal(root); // Assuming this is your solution for 94
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << got << " expected=" << expect << "\n";
        } else {
            ++idx;
        }
        free_tree(root); // You must implement this helper if not present
        all &= ok;
    }
    return all;
}

bool lc_test_98(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::vector<std::optional<int>> tree;
        for (const auto& val : tc.at("tree")) {
            if (val.is_null()) tree.push_back(std::nullopt);
            else tree.push_back(val.get<int>());
        }
        bool expect = tc.at("expected").get<bool>();
        TreeNode* root = build_tree_from_level_order(tree);
        bool got = isValidBST(root);
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << (got?"true":"false") << " expected=" << (expect?"true":"false") << "\n";
        } else {
            ++idx;
        }
        free_tree(root);
        all &= ok;
    }
    return all;
}


bool lc_test_104(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::vector<std::optional<int>> tree;
        for (const auto& val : tc.at("tree")) {
            if (val.is_null()) tree.push_back(std::nullopt);
            else tree.push_back(val.get<int>());
        }
        int expect = tc.at("expected").get<int>();
        TreeNode* root = build_tree_from_level_order(tree);
        int got = maxDepth(root); // assumes global or Solution::maxDepth
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << got << " expected=" << expect << "\n";
        } else {
            ++idx;
        }
        free_tree(root);
        all &= ok;
    }
    return all;
}

bool lc_test_102(const json& j) {
    // Each case has a tree (level order with nulls) and expected 2D vector
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::vector<std::optional<int>> data;
        for (const auto& val : tc.at("tree")) {
            if (val.is_null()) data.push_back(std::nullopt); else data.push_back(val.get<int>());
        }
        std::vector<std::vector<int>> expect = tc.at("expected").get<std::vector<std::vector<int>>>();
        TreeNode* root = build_tree_from_level_order(data);
        std::vector<std::vector<int>> got = levelOrder(root);
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=";
            std::cout << "[";
            for (size_t i=0;i<got.size();++i){ if(i) std::cout<<"|"; std::cout<<"["; for(size_t j=0;j<got[i].size();++j){ if(j) std::cout<<","; std::cout<<got[i][j]; } std::cout<<"]"; }
            std::cout << "] expected=";
            std::cout << "[";
            for (size_t i=0;i<expect.size();++i){ if(i) std::cout<<"|"; std::cout<<"["; for(size_t j=0;j<expect[i].size();++j){ if(j) std::cout<<","; std::cout<<expect[i][j]; } std::cout<<"]"; }
            std::cout << "]\n";
        } else { ++idx; }
        free_tree(root);
        all &= ok;
    }
    return all;
}

bool lc_test_103(const json& j) {
    bool all = true; size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::vector<std::optional<int>> data;
        for (const auto& v : tc.at("tree")) {
            if (v.is_null()) data.push_back(std::nullopt); else data.push_back(v.get<int>());
        }
        std::vector<std::vector<int>> expect = tc.at("expected").get<std::vector<std::vector<int>>>();
        TreeNode* root = build_tree_from_level_order(data);
        auto got = zigzagLevelOrder(root);
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=";
            std::cout << "["; for(size_t i=0;i<got.size();++i){ if(i) std::cout<<"|"; std::cout<<"["; for(size_t j=0;j<got[i].size();++j){ if(j) std::cout<<","; std::cout<<got[i][j]; } std::cout<<"]"; } std::cout << "] expected=";
            std::cout << "["; for(size_t i=0;i<expect.size();++i){ if(i) std::cout<<"|"; std::cout<<"["; for(size_t j=0;j<expect[i].size();++j){ if(j) std::cout<<","; std::cout<<expect[i][j]; } std::cout<<"]"; } std::cout << "]\n";
        } else { ++idx; }
        free_tree(root);
        all &= ok;
    }
    return all;
}

bool lc_test_100(const json& j) {
    // Each case contains two trees (p and q) and expected boolean
    bool all = true; size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::vector<std::optional<int>> dataP, dataQ;
        for (const auto& v : tc.at("p")) { if (v.is_null()) dataP.push_back(std::nullopt); else dataP.push_back(v.get<int>()); }
        for (const auto& v : tc.at("q")) { if (v.is_null()) dataQ.push_back(std::nullopt); else dataQ.push_back(v.get<int>()); }
        bool expect = tc.at("expected").get<bool>();
        TreeNode* pRoot = build_tree_from_level_order(dataP);
        TreeNode* qRoot = build_tree_from_level_order(dataQ);
        bool got = isSameTree(pRoot, qRoot);
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << (got?"true":"false") << " expected=" << (expect?"true":"false") << "\n";
        } else { ++idx; }
        free_tree(pRoot); free_tree(qRoot);
        all &= ok;
    }
    return all;
}

bool lc_test_110(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::vector<std::optional<int>> tree;
        for (const auto& val : tc.at("tree")) {
            if (val.is_null()) tree.push_back(std::nullopt);
            else tree.push_back(val.get<int>());
        }
        bool expect = tc.at("expected").get<bool>();
        TreeNode* root = build_tree_from_level_order(tree);
        bool got = isBalanced(root);
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << (got ? "true" : "false") << " expected=" << (expect ? "true" : "false") << "\n";
        } else {
            ++idx;
        }
        free_tree(root);
        all &= ok;
    }
    return all;
}

bool lc_test_424(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::string s = tc.at("input").get<std::string>();
        int k = tc.at("k").get<int>();
        int expect = tc.at("expected").get<int>();
        int got = characterReplacement(s, k);
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << got << " expected=" << expect << "\n";
        } else {
            ++idx;
        }
        all &= ok;
    }
    return all;
}

bool lc_test_438(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::string s = tc.at("s").get<std::string>();
        std::string p = tc.at("p").get<std::string>();
        std::vector<int> expect = tc.at("expected").get<std::vector<int>>();
        std::vector<int> got = findAnagrams(s, p);
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << got << " expected=" << expect << "\n";
        } else {
            ++idx;
        }
        all &= ok;
    }
    return all;
}

bool lc_test_567(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::string s1 = tc.at("s1").get<std::string>();
        std::string s2 = tc.at("s2").get<std::string>();
        bool expect = tc.at("expected").get<bool>();
        bool got = checkInclusion(s1, s2);
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << (got ? "true" : "false") << " expected=" << (expect ? "true" : "false") << "\n";
        } else {
            ++idx;
        }
        all &= ok;
    }
    return all;
}

bool lc_test_20(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::string input = tc.at("input").get<std::string>();
        bool expect = tc.at("expected").get<bool>();
        bool got = isValid(input);
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  input=\"" << input << "\" got=" << (got ? "true" : "false") << " expected=" << (expect ? "true" : "false") << "\n";
        } else {
            ++idx;
        }
        all &= ok;
    }
    return all;
}

bool lc_test_739(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::vector<int> input = tc.at("input").get<std::vector<int>>();
        std::vector<int> expect = tc.at("expected").get<std::vector<int>>();
        std::vector<int> got = dailyTemperatures(input);
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << got << " expected=" << expect << "\n";
        } else {
            ++idx;
        }
        all &= ok;
    }
    return all;
}

bool lc_test_35(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::vector<int> nums = tc.at("nums").get<std::vector<int>>();
        int target = tc.at("target").get<int>();
        int expect = tc.at("expected").get<int>();
        int got = searchInsert(nums, target);
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << got << " expected=" << expect << "\n";
        } else {
            ++idx;
        }
        all &= ok;
    }
    return all;
}

bool lc_test_36(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        // Parse board from strings to chars
        std::vector<std::vector<char>> board;
        for (const auto& row : tc.at("board")) {
            std::vector<char> boardRow;
            for (const auto& cell : row) {
                std::string cellStr = cell.get<std::string>();
                boardRow.push_back(cellStr[0]);  // Convert string to char
            }
            board.push_back(boardRow);
        }
        
        bool expect = tc.at("expected").get<bool>();
        bool got = isValidSudoku(board);
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << got << " expected=" << expect << "\n";
        } else {
            ++idx;
        }
        all &= ok;
    }
    return all;
}

bool lc_test_160(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::vector<int> listA_arr = tc.at("listA").get<std::vector<int>>();
        std::vector<int> listB_arr = tc.at("listB").get<std::vector<int>>();
        
        ListNode* headA = vec_to_list(listA_arr);
        ListNode* headB = vec_to_list(listB_arr);
        
        // Create intersection if specified
        int intersectVal = tc.contains("intersectVal") ? tc.at("intersectVal").get<int>() : 0;
        if (intersectVal != 0) {
            int skipA = tc.at("skipA").get<int>();
            int skipB = tc.at("skipB").get<int>();
            
            // Find intersection node in listA
            ListNode* nodeA = headA;
            for (int i = 0; i < skipA; ++i) nodeA = nodeA->next;
            
            // Find node in listB to connect
            ListNode* nodeB = headB;
            for (int i = 0; i < skipB - 1; ++i) nodeB = nodeB->next;
            
            // Connect to shared portion
            nodeB->next = nodeA;
        }
        
        auto expect_val = tc.contains("expected") && !tc.at("expected").is_null() 
                         ? tc.at("expected").get<int>() : -1;
        
        ListNode* got_node = getIntersectionNode(headA, headB);
        int got_val = got_node ? got_node->val : -1;
        
        bool ok = (got_val == expect_val);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << got_val << " expected=" << expect_val << "\n";
        } else {
            ++idx;
        }
        all &= ok;
    }
    return all;
}

bool lc_test_200(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        // Parse grid from strings to chars
        std::vector<std::vector<char>> grid;
        for (const auto& row : tc.at("grid")) {
            std::vector<char> gridRow;
            for (const auto& cell : row) {
                std::string cellStr = cell.get<std::string>();
                gridRow.push_back(cellStr[0]);  // Convert string to char
            }
            grid.push_back(gridRow);
        }
        
        int expect = tc.at("expected").get<int>();
        int got = numIslands(grid);
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << got << " expected=" << expect << "\n";
        } else {
            ++idx;
        }
        all &= ok;
    }
    return all;
}

bool lc_test_206(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::vector<int> head_arr = tc.at("head").get<std::vector<int>>();
        std::vector<int> expect = tc.at("expected").get<std::vector<int>>();
        
        ListNode* head = vec_to_list(head_arr);
        ListNode* got_head = reverseList(head);
        std::vector<int> got = list_to_vec(got_head);
        
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << got << " expected=" << expect << "\n";
        } else {
            ++idx;
        }
        all &= ok;
    }
    return all;
}

bool lc_test_226(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::vector<int> root_arr = tc.at("root").get<std::vector<int>>();
        std::vector<int> expect = tc.at("expected").get<std::vector<int>>();
        
        TreeNode* root = vec_to_tree(root_arr);
        TreeNode* got_root = invertTree(root);
        std::vector<int> got = tree_to_vec(got_root);
        
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << got << " expected=" << expect << "\n";
        } else {
            ++idx;
        }
        all &= ok;
    }
    return all;
}

bool lc_test_238(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::vector<int> nums = tc.at("nums").get<std::vector<int>>();
        std::vector<int> expect = tc.at("expected").get<std::vector<int>>();
        std::vector<int> got = productExceptSelf(nums);
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << got << " expected=" << expect << "\n";
        } else {
            ++idx;
        }
        all &= ok;
    }
    return all;
}

bool lc_test_560(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::vector<int> nums = tc.at("nums").get<std::vector<int>>();
        int k = tc.at("k").get<int>();
        int expect = tc.at("expected").get<int>();
        int got = subarraySum(nums, k);
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << got << " expected=" << expect << "\n";
        } else {
            ++idx;
        }
        all &= ok;
    }
    return all;
}

TreeNode* vec_to_tree(const std::vector<int>& data) {
    if (data.empty()) return nullptr;
    TreeNode* root = new TreeNode(data[0]);
    std::queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;
    while (!q.empty() && i < data.size()) {
        TreeNode* node = q.front(); q.pop();
        if (i < data.size() && data[i] != -1) {  // Use -1 as null marker
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

std::vector<int> tree_to_vec(TreeNode* root) {
    if (!root) return {};
    std::vector<int> result;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (node) {
            result.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        } else {
            result.push_back(-1);  // Use -1 as null marker
        }
    }
    // Remove trailing nulls
    while (!result.empty() && result.back() == -1) {
        result.pop_back();
    }
    return result;
}

bool lc_test_139(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        std::string s = tc.at("s").get<std::string>();
        std::vector<std::string> wordDict = tc.at("wordDict").get<std::vector<std::string>>();
        bool expect = tc.at("expected").get<bool>();
        bool got = wordBreak(s, wordDict);
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  s=\"" << s << "\" got=" << (got ? "true" : "false") << " expected=" << (expect ? "true" : "false") << "\n";
        } else {
            ++idx;
        }
        all &= ok;
    }
    return all;
}

bool lc_test_70(const json& j) {
    bool all = true;
    size_t idx = 0;
    for (const auto& tc : j.at("cases")) {
        int n = tc.at("n").get<int>();
        int expect = tc.at("expected").get<int>();
        int got = climbStairs(n);
        bool ok = (got == expect);
        if (!ok) {
            std::cout << "  Case " << (++idx) << ": FAIL  got=" << got << " expected=" << expect << " (n=" << n << ")\n";
        } else {
            ++idx;
        }
        all &= ok;
    }
    return all;
}

std::string get_testcases_json_path() {
    const char* env = std::getenv("REPO_ROOT");
    if (env) {
        return std::string(env) + "/testcases.json";
    }
    // fallback paths
    const char* paths[] = {
        "../testcases.json",
        "testcases.json",
        "src/testcases.json",
        "src/cpp/testcases.json",
        "src/go/testcases.json"
    };
    for (auto p : paths) {
        std::ifstream in(p);
        if (in.good()) return p;
    }
    return "testcases.json";
}
