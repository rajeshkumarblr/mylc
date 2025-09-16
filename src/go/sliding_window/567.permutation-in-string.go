package main

func checkInclusion(s1 string, s2 string) bool {
	if len(s1) > len(s2) {
		return false
	}
	count := [26]int{}
	for i := 0; i < len(s1); i++ {
		count[s1[i]-'a']++
		count[s2[i]-'a']--
	}
	if allZero(count[:]) {
		return true
	}
	for i := len(s1); i < len(s2); i++ {
		count[s2[i]-'a']--
		count[s2[i-len(s1)]-'a']++
		if allZero(count[:]) {
			return true
		}
	}
	return false
}
