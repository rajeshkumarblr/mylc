package main

func wordBreak(s string, wordDict []string) bool {
	n := len(s)
	dp := make([]bool, n+1)
	dp[0] = true // Empty string can always be broken

	// Convert wordDict to map for O(1) lookup
	wordSet := make(map[string]bool)
	for _, word := range wordDict {
		wordSet[word] = true
	}

	for i := 1; i <= n; i++ {
		for j := 0; j < i; j++ {
			word := s[j:i]
			if dp[j] && wordSet[word] {
				dp[i] = true
				break
			}
		}
	}

	return dp[n]
}
