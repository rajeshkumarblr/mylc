#include <set>
#include <cmath>
#include <map>
#include <nlohmann/json.hpp>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 *
 * Difficulty: Medium
 * Category: stack
 * URL: https://leetcode.com/problems/min-stack/
 *
 * Description:
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 *  Implement the  MinStack  class:
 *           MinStack()  initializes the stack object.
 *           void push(int value)  pushes the element  value  onto the stack.
 *           void pop()  removes the element on the top of the stack.
 *           int top()  gets the top element of the stack.
 *           int getMin()  retrieves the minimum element in the stack.
 *  You must implement a solution with  O(1)  time complexity for each
 * function.
 *   Example 1:
 *  Input
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 *  Output
 * [null,null,null,null,-3,null,0,-2]
 *  Explanation
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin(); // return -3
 * minStack.pop();
 * minStack.top();    // return 0
 * minStack.getMin(); // return -2
 *   Constraints:
 *           -2 31  <= val <= 2 31  - 1
 *          Methods  pop ,  top  and  getMin  operations will always be called
 * on  non-empty  stacks.
 *          At most  3 * 10 4   calls will be made to  push ,  pop ,  top ,
 * and  getMin .
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;
using json = nlohmann::json;
using json = nlohmann::json;
using json = nlohmann::json;
using json = nlohmann::json;
using json = nlohmann::json;


// @lc code=start
class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int value) {
        
    }
    
    void pop() {
        
    }
    
    int top() {
        
    }
    
    int getMin() {
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end


int main() {
    cerr << "FAIL (No test cases)" << endl;
    return 1;
}
