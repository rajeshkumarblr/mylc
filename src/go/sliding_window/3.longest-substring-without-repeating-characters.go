package main

func lengthOfLongestSubstring(s string) int {
	m := make(map[byte]int)
	maxLen := 0
	left := 0
	for right := 0; right < len(s); right++ {
		if idx, ok := m[s[right]]; ok && idx >= left {
			left = idx + 1
		}
		m[s[right]] = right
		if right-left+1 > maxLen {
			maxLen = right - left + 1
		}
	}
	return maxLen
}
