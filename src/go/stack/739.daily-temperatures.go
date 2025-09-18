package main

// Daily Temperatures (LC 739)
// Monotonic decreasing stack of indices; when we see a warmer day, we pop and fill the wait.
func dailyTemperatures(temperatures []int) []int {
	res := make([]int, len(temperatures))
	stack := make([]int, 0, len(temperatures)) // holds indices with decreasing temps

	for i, t := range temperatures {
		for len(stack) > 0 && t > temperatures[stack[len(stack)-1]] {
			j := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			res[j] = i - j
		}
		stack = append(stack, i)
	}
	return res
}
