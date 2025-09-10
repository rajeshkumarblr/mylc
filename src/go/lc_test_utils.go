package main

import (
	"fmt"
	"os"
	"strconv"
)

// Generic equality for []int
func equalIntSlice(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

// Generic test runner for []int -> []int functions
func RunVecIntTests(fn func([]int) []int, tests []struct {
	input    []int
	expected []int
}) bool {
	iters := 1
	if s := os.Getenv("LC_STRESS_ITERS"); s != "" {
		if v, err := strconv.Atoi(s); err == nil && v > 0 {
			iters = v
		}
	}
	ok := true
	for i := 0; i < iters && ok; i++ {
		for idx, tc := range tests {
			got := fn(tc.input)
			if !equalIntSlice(got, tc.expected) {
				ok = false
				fmt.Printf("FAIL at case %d: got=%v want=%v\n", idx, got, tc.expected)
				break
			}
		}
	}
	return ok
}

// Generic test runner for []int -> int functions
func RunVecIntToIntTests(fn func([]int) int, tests []struct {
	input    []int
	expected int
}) bool {
	iters := 1
	if s := os.Getenv("LC_STRESS_ITERS"); s != "" {
		if v, err := strconv.Atoi(s); err == nil && v > 0 {
			iters = v
		}
	}
	ok := true
	for i := 0; i < iters && ok; i++ {
		for idx, tc := range tests {
			got := fn(tc.input)
			if got != tc.expected {
				ok = false
				fmt.Printf("FAIL at case %d: got=%d want=%d\n", idx, got, tc.expected)
				break
			}
		}
	}
	return ok
}

// Generic test runner for ([]int, int) -> []int functions (like Two Sum)
func RunVecIntIntToVecIntTests(fn func([]int, int) []int, tests []struct {
	nums     []int
	target   int
	expected []int
}) bool {
	iters := 1
	if s := os.Getenv("LC_STRESS_ITERS"); s != "" {
		if v, err := strconv.Atoi(s); err == nil && v > 0 {
			iters = v
		}
	}
	ok := true
	for i := 0; i < iters && ok; i++ {
		for idx, tc := range tests {
			got := fn(tc.nums, tc.target)
			if !equalIntSlice(got, tc.expected) {
				ok = false
				fmt.Printf("FAIL at case %d: got=%v want=%v\n", idx, got, tc.expected)
				break
			}
		}
	}
	return ok
}
