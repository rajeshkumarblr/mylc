package main

/*
 * @lc app=leetcode id=160 lang=golang
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
func getIntersectionNode(headA, headB *ListNode) *ListNode {
	if headA == nil || headB == nil {
		return nil
	}

	pA, pB := headA, headB

	for pA != pB {
		if pA == nil {
			pA = headB
		} else {
			pA = pA.Next
		}

		if pB == nil {
			pB = headA
		} else {
			pB = pB.Next
		}
	}

	return pA
}

// @lc code=end
