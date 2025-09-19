package main

import (
	"fmt"
	"os"
)

var funcRegistry = map[string]interface{}{
	"1":   twoSum,
	"2":   addTwoNumbers,
	"3":   lengthOfLongestSubstring,
	"9":   isPalindrome,
	"11":  maxArea,
	"21":  mergeTwoLists,
	"42":  trap,
	"98":  isValidBST,
	"94":  inorderTraversal,
	"100": isSameTree,
	"102": levelOrder,
	"103": zigzagLevelOrder,
	"104": maxDepth,
	"110": isBalanced,
	"424": characterReplacement,
	"438": findAnagrams,
	"567": checkInclusion,
	"739": dailyTemperatures,
	// Add more problems here as needed
}

func main() {
	category := os.Getenv("LC_CATEGORY")
	if category != "" {
		ok := RunAllTestsByCategory(funcRegistry, category)
		if ok {
			fmt.Println("Final Result: PASS yes")
			os.Exit(0)
		} else {
			fmt.Println("Final Result: FAIL")
			os.Exit(1)
		}
		return
	}

	probNum := os.Getenv("LC_PROB_NUM")
	if probNum == "all" { // explicit all
		ok := RunAllTests(funcRegistry)
		if ok {
			fmt.Println("Final Result: PASS yes")
			os.Exit(0)
		} else {
			fmt.Println("Final Result: FAIL")
			os.Exit(1)
		}
	} else if probNum != "" { // single problem
		ok := RunAllTestsFiltered(funcRegistry, probNum)
		if ok {
			fmt.Println("Final Result: PASS yes")
			os.Exit(0)
		} else {
			fmt.Println("Final Result: FAIL")
			os.Exit(1)
		}
	} else { // default run all
		ok := RunAllTests(funcRegistry)
		if ok {
			fmt.Println("Final Result: PASS yes")
			os.Exit(0)
		} else {
			fmt.Println("Final Result: FAIL")
			os.Exit(1)
		}
	}
}
