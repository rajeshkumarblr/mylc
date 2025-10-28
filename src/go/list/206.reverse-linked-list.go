package main

/*
 * @lc app=leetcode id=206 lang=golang
 *
 * [206] Reverse Linked List
 */

// @lc code=start
func reverseList(head *ListNode) *ListNode {
	var prev *ListNode
	curr := head

	for curr != nil {
		next := curr.Next
		curr.Next = prev
		prev = curr
		curr = next
	}

	return prev
}

// @lc code=end
