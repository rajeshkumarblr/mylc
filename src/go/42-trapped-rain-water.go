package main

import (
	"fmt"
	"os"
	"strconv"
)

func trapTwoPointer(height []int) int {
	n := len(height)
	if n <= 2 {
		return 0
	}
	l, r := 0, n-1
	leftMax, rightMax := height[l], height[r]
	res := 0

	for l < r {
		if leftMax < rightMax {
			l++
			if height[l] > leftMax {
				leftMax = height[l]
			}
			res += leftMax - height[l]
		} else {
			r--
			if height[r] > rightMax {
				rightMax = height[r]
			}
			res += rightMax - height[r]
		}
	}
	return res
}

// Optional alt approach (prefix/suffix max) for parity/debug.
func trapMinMax(height []int) int {
	n := len(height)
	if n <= 2 {
		return 0
	}
	maxLeft := make([]int, n)
	maxRight := make([]int, n)

	m := height[0]
	for i := 1; i < n; i++ {
		if height[i] > m {
			m = height[i]
		}
		maxLeft[i] = m
	}
	m = height[n-1]
	for i := n - 2; i >= 0; i-- {
		if height[i] > m {
			m = height[i]
		}
		maxRight[i] = m
	}

	res := 0
	for i := 1; i < n; i++ {
		minLR := maxLeft[i]
		if maxRight[i] < minLR {
			minLR = maxRight[i]
		}
		if minLR > height[i] {
			res += (minLR - height[i])
		}
	}
	return res
}

type testCase struct {
	h    []int
	want int
}

func main() {
	tests := []testCase{
		{[]int{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}, 6},
		{[]int{4, 2, 0, 3, 2, 5}, 9},
		{[]int{1, 2, 3, 4, 5}, 0},
		{[]int{5, 4, 1, 2}, 1},
		{[]int{2, 0, 2}, 2},
		{[]int{}, 0},
	}

	iters := 1
	if s := os.Getenv("LC_STRESS_ITERS"); s != "" {
		if v, err := strconv.Atoi(s); err == nil && v > 0 {
			iters = v
		}
	}

	ok := true
	for i := 0; i < iters && ok; i++ {
		for idx, tc := range tests {
			got := trapTwoPointer(tc.h)
			if got != tc.want {
				ok = false
				fmt.Printf("FAIL at case %d: got=%d want=%d\n", idx, got, tc.want)
				break
			}
		}
	}

	if ok {
		fmt.Println("Final Result: PASS yes")
		os.Exit(0)
	} else {
		fmt.Println("Final Result: FAIL")
		os.Exit(1)
	}
}
