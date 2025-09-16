package main

func findAnagrams(s string, p string) []int {
	res := []int{}
	if len(s) < len(p) {
		return res
	}
	count := [26]int{}
	for i := 0; i < len(p); i++ {
		count[p[i]-'a']++
		count[s[i]-'a']--
	}
	if allZero(count[:]) {
		res = append(res, 0)
	}
	for i := len(p); i < len(s); i++ {
		count[s[i]-'a']--
		count[s[i-len(p)]-'a']++
		if allZero(count[:]) {
			res = append(res, i-len(p)+1)
		}
	}
	return res
}
