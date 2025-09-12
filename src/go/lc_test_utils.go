package main

import (
	"encoding/json"
	"fmt"
	"os"
	"reflect"
)

// Shared ListNode and TreeNode definitions
type ListNode struct {
	Val  int
	Next *ListNode
}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// Shared allZero helper
func allZero(arr []int) bool {
	for _, v := range arr {
		if v != 0 {
			return false
		}
	}
	return true
}

type FuncType int

const (
	SliceToInt FuncType = iota
	SliceIntToSliceInt
)

type FuncEntry struct {
	Typ FuncType
	Fn  interface{}
}

func runTests(probNum string, entry FuncEntry, tests []map[string]interface{}) bool {
	ok := true
	for idx, tc := range tests {
		inputIface := tc["input"].([]interface{})
		input := make([]int, len(inputIface))
		for i, v := range inputIface {
			input[i] = int(v.(float64))
		}
		switch entry.Typ {
		case SliceToInt:
			expected := int(tc["expected"].(float64))
			got := entry.Fn.(func([]int) int)(input)
			if got != expected {
				fmt.Printf("  FAIL at case %d: got=%d want=%d\n", idx, got, expected)
				ok = false
			} else {
				fmt.Printf("  PASS at case %d\n", idx)
			}
		case SliceIntToSliceInt:
			target := int(tc["target"].(float64))
			expectedIface := tc["expected"].([]interface{})
			expected := make([]int, len(expectedIface))
			for i, v := range expectedIface {
				expected[i] = int(v.(float64))
			}
			got := entry.Fn.(func([]int, int) []int)(input, target)
			if !reflect.DeepEqual(got, expected) {
				fmt.Printf("  FAIL at case %d: got=%v want=%v\n", idx, got, expected)
				ok = false
			} else {
				fmt.Printf("  PASS at case %d\n", idx)
			}
		}
	}
	return ok
}

// Generic test runner for problems with signature func([]int) int
func RunSliceToIntTests(fn func([]int) int, tests []map[string]interface{}) bool {
	ok := true
	for idx, tc := range tests {
		inputIface := tc["input"].([]interface{})
		input := make([]int, len(inputIface))
		for i, v := range inputIface {
			input[i] = int(v.(float64))
		}
		expected := int(tc["expected"].(float64))
		got := fn(input)
		if got != expected {
			fmt.Printf("  FAIL at case %d: got=%d want=%d\n", idx, got, expected)
			ok = false
		} else {
			fmt.Printf("  PASS at case %d\n", idx)
		}
	}
	return ok
}

// Generic test runner for problems with signature func([]int, int) []int
func RunSliceIntToSliceIntTests(fn func([]int, int) []int, tests []map[string]interface{}) bool {
	ok := true
	for idx, tc := range tests {
		inputIface := tc["input"].([]interface{})
		input := make([]int, len(inputIface))
		for i, v := range inputIface {
			input[i] = int(v.(float64))
		}
		target := int(tc["target"].(float64))
		expectedIface := tc["expected"].([]interface{})
		expected := make([]int, len(expectedIface))
		for i, v := range expectedIface {
			expected[i] = int(v.(float64))
		}
		got := fn(input, target)
		if !reflect.DeepEqual(got, expected) {
			fmt.Printf("  FAIL at case %d: got=%v want=%v\n", idx, got, expected)
			ok = false
		} else {
			fmt.Printf("  PASS at case %d\n", idx)
		}
	}
	return ok
}

// Top-level test runner: parses testcases.json and dispatches to the correct generic runner

var problemDescriptions = map[string]string{
	"1":   "two sum",
	"2":   "add two numbers",
	"3":   "longest substring",
	"9":   "palindrome number",
	"11":  "container with most water",
	"21":  "merge two sorted lists",
	"42":  "trapping rain water",
	"94":  "inorder traversal",
	"104": "max depth",
	"110": "is balanced",
	"424": "character replacement",
	"438": "find all anagrams",
	"567": "permutation in string",
}

type ProblemTest struct {
	Category string                   `json:"category"`
	Cases    []map[string]interface{} `json:"cases"`
}

// Run all tests for problems in a given category
func RunAllTestsByCategory(funcRegistry map[string]interface{}, category string) bool {
	file, err := openTestcasesFile()
	if err != nil {
		fmt.Println("Error opening testcases.json:", err)
		return false
	}
	defer file.Close()

	var allTests map[string]ProblemTest
	if err := json.NewDecoder(file).Decode(&allTests); err != nil {
		fmt.Println("Error decoding testcases:", err)
		return false
	}

	type summaryRow struct {
		Num         string
		Description string
		Category    string
		Result      string
		Cases       []int
	}
	var summary []summaryRow
	allOk := true

	for probNum, probTest := range allTests {
		if probTest.Category != category {
			continue
		}
		fn, found := funcRegistry[probNum]
		if !found {
			summary = append(summary, summaryRow{probNum, problemDescriptions[probNum], "", "NoFunc", nil})
			allOk = false
			continue
		}
		tests := probTest.Cases
		caseResults := make([]string, len(tests))
		caseIndices := make([]int, 0, len(tests))
		ok := true
		switch probNum {
		case "1":
			for idx, tc := range tests {
				inputIface := tc["input"].([]interface{})
				input := make([]int, len(inputIface))
				for i, v := range inputIface {
					input[i] = int(v.(float64))
				}
				target := int(tc["target"].(float64))
				expectedIface := tc["expected"].([]interface{})
				expected := make([]int, len(expectedIface))
				for i, v := range expectedIface {
					expected[i] = int(v.(float64))
				}
				got := fn.(func([]int, int) []int)(input, target)
				if reflect.DeepEqual(got, expected) {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
				}
			}
		// ...existing code for other problems...
		default:
			// ...existing code for other problems...
		}
		result := "PASS"
		if !ok {
			result = "FAIL"
			allOk = false
		}
		summary = append(summary, summaryRow{probNum, problemDescriptions[probNum], probTest.Category, result, caseIndices})
	}

	// Print summary
	fmt.Printf("%-6s %-30s %-15s %-6s %s\n", "Num", "Description", "Category", "Result", "Cases")
	for _, row := range summary {
		fmt.Printf("%-6s %-30s %-15s %-6s %v\n", row.Num, row.Description, row.Category, row.Result, row.Cases)
	}
	return allOk
}

func RunAllTests(funcRegistry map[string]interface{}) bool {
	file, err := openTestcasesFile()
	if err != nil {
		fmt.Println("Error opening testcases.json:", err)
		return false
	}
	defer file.Close()

	var allTests map[string]ProblemTest
	if err := json.NewDecoder(file).Decode(&allTests); err != nil {
		fmt.Println("Error decoding testcases:", err)
		return false
	}

	probNumFilter := os.Getenv("LC_PROB_NUM")

	type summaryRow struct {
		Num         string
		Description string
		Category    string
		Result      string
		Cases       []int
	}
	var summary []summaryRow
	allOk := true

	for probNum, probTest := range allTests {
		if probNumFilter != "" && probNum != probNumFilter {
			continue
		}
		fn, found := funcRegistry[probNum]
		if !found {
			summary = append(summary, summaryRow{probNum, problemDescriptions[probNum], "", "NoFunc", nil})
			allOk = false
			continue
		}
		tests := probTest.Cases
		caseResults := make([]string, len(tests))
		caseIndices := make([]int, 0, len(tests))
		ok := true
		switch probNum {
		case "1":
			for idx, tc := range tests {
				inputIface := tc["input"].([]interface{})
				input := make([]int, len(inputIface))
				for i, v := range inputIface {
					input[i] = int(v.(float64))
				}
				target := int(tc["target"].(float64))
				expectedIface := tc["expected"].([]interface{})
				expected := make([]int, len(expectedIface))
				for i, v := range expectedIface {
					expected[i] = int(v.(float64))
				}
				got := fn.(func([]int, int) []int)(input, target)
				if reflect.DeepEqual(got, expected) {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "2":
			for idx, tc := range tests {
				l1Iface := tc["l1"].([]interface{})
				l2Iface := tc["l2"].([]interface{})
				l1 := buildList(l1Iface)
				l2 := buildList(l2Iface)
				expectedIface := tc["expected"].([]interface{})
				expected := buildList(expectedIface)
				got := fn.(func(*ListNode, *ListNode) *ListNode)(l1, l2)
				if compareLists(got, expected) {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "3":
			for idx, tc := range tests {
				input := tc["input"].(string)
				expected := int(tc["expected"].(float64))
				got := fn.(func(string) int)(input)
				if got == expected {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "9":
			for idx, tc := range tests {
				input := int(tc["input"].(float64))
				expected := tc["expected"].(bool)
				got := fn.(func(int) bool)(input)
				if got == expected {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "11":
			for idx, tc := range tests {
				inputIface := tc["input"].([]interface{})
				input := make([]int, len(inputIface))
				for i, v := range inputIface {
					input[i] = int(v.(float64))
				}
				expected := int(tc["expected"].(float64))
				got := fn.(func([]int) int)(input)
				if got == expected {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "21":
			for idx, tc := range tests {
				l1Iface := tc["l1"].([]interface{})
				l2Iface := tc["l2"].([]interface{})
				l1 := buildList(l1Iface)
				l2 := buildList(l2Iface)
				expectedIface := tc["expected"].([]interface{})
				expected := buildList(expectedIface)
				got := fn.(func(*ListNode, *ListNode) *ListNode)(l1, l2)
				if compareLists(got, expected) {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "42":
			for idx, tc := range tests {
				inputIface := tc["input"].([]interface{})
				input := make([]int, len(inputIface))
				for i, v := range inputIface {
					input[i] = int(v.(float64))
				}
				expected := int(tc["expected"].(float64))
				got := fn.(func([]int) int)(input)
				if got == expected {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "94":
			for idx, tc := range tests {
				vals := tc["tree"].([]interface{})
				root := buildTree(vals)
				expectedIface := tc["expected"].([]interface{})
				expected := make([]int, len(expectedIface))
				for i, v := range expectedIface {
					expected[i] = int(v.(float64))
				}
				got := fn.(func(*TreeNode) []int)(root)
				if compareSlices(got, expected) {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "104":
			for idx, tc := range tests {
				vals := tc["tree"].([]interface{})
				root := buildTree(vals)
				expected := int(tc["expected"].(float64))
				got := fn.(func(*TreeNode) int)(root)
				if got == expected {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "110":
			for idx, tc := range tests {
				vals := tc["tree"].([]interface{})
				root := buildTree(vals)
				expected := tc["expected"].(bool)
				got := fn.(func(*TreeNode) bool)(root)
				if got == expected {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "424":
			for idx, tc := range tests {
				input := tc["input"].(string)
				k := int(tc["k"].(float64))
				expected := int(tc["expected"].(float64))
				got := fn.(func(string, int) int)(input, k)
				if got == expected {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "438":
			for idx, tc := range tests {
				s := tc["s"].(string)
				p := tc["p"].(string)
				expectedIface := tc["expected"].([]interface{})
				expected := make([]int, len(expectedIface))
				for i, v := range expectedIface {
					expected[i] = int(v.(float64))
				}
				got := fn.(func(string, string) []int)(s, p)
				if reflect.DeepEqual(got, expected) {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "567":
			for idx, tc := range tests {
				s1 := tc["s1"].(string)
				s2 := tc["s2"].(string)
				expected := tc["expected"].(bool)
				got := fn.(func(string, string) bool)(s1, s2)
				if got == expected {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		default:
			caseResults[0] = "NoRunner"
			ok = false
		}
		result := "Pass"
		for _, r := range caseResults {
			if r != "Pass" {
				result = "Fail"
				break
			}
		}
		desc := problemDescriptions[probNum]
		if desc == "" {
			desc = "?"
		}
		summary = append(summary, summaryRow{probNum, desc, probTest.Category, result, caseIndices})
		if !ok {
			allOk = false
		}
	}

	fmt.Printf("%-4s %-25s %-15s %-6s %s\n", "No", "Description", "Category", "Result", "Cases")
	for _, row := range summary {
		fmt.Printf("%-4s %-25s %-15s %-6s %v\n", row.Num, row.Description, row.Category, row.Result, row.Cases)
	}

	return allOk
}

func RunAllTestsFiltered(funcRegistry map[string]interface{}, probNumFilter string) bool {
	file, err := openTestcasesFile()
	if err != nil {
		fmt.Println("Error opening testcases.json:", err)
		return false
	}
	defer file.Close()

	var allTests map[string]ProblemTest
	if err := json.NewDecoder(file).Decode(&allTests); err != nil {
		fmt.Println("Error decoding testcases:", err)
		return false
	}

	type summaryRow struct {
		Num         string
		Description string
		Category    string
		Result      string
		Cases       []int
	}
	var summary []summaryRow
	allOk := true

	for probNum, probTest := range allTests {
		if probNum != probNumFilter {
			continue
		}
		fn, found := funcRegistry[probNum]
		if !found {
			summary = append(summary, summaryRow{probNum, problemDescriptions[probNum], "", "NoFunc", nil})
			allOk = false
			continue
		}
		tests := probTest.Cases
		caseResults := make([]string, len(tests))
		caseIndices := make([]int, 0, len(tests))
		ok := true
		switch probNum {
		case "1":
			for idx, tc := range tests {
				inputIface := tc["input"].([]interface{})
				input := make([]int, len(inputIface))
				for i, v := range inputIface {
					input[i] = int(v.(float64))
				}
				target := int(tc["target"].(float64))
				expectedIface := tc["expected"].([]interface{})
				expected := make([]int, len(expectedIface))
				for i, v := range expectedIface {
					expected[i] = int(v.(float64))
				}
				got := fn.(func([]int, int) []int)(input, target)
				if reflect.DeepEqual(got, expected) {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "2":
			for idx, tc := range tests {
				l1Iface := tc["l1"].([]interface{})
				l2Iface := tc["l2"].([]interface{})
				l1 := buildList(l1Iface)
				l2 := buildList(l2Iface)
				expectedIface := tc["expected"].([]interface{})
				expected := buildList(expectedIface)
				got := fn.(func(*ListNode, *ListNode) *ListNode)(l1, l2)
				if compareLists(got, expected) {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "3":
			for idx, tc := range tests {
				input := tc["input"].(string)
				expected := int(tc["expected"].(float64))
				got := fn.(func(string) int)(input)
				if got == expected {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "9":
			for idx, tc := range tests {
				input := int(tc["input"].(float64))
				expected := tc["expected"].(bool)
				got := fn.(func(int) bool)(input)
				if got == expected {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "11":
			for idx, tc := range tests {
				inputIface := tc["input"].([]interface{})
				input := make([]int, len(inputIface))
				for i, v := range inputIface {
					input[i] = int(v.(float64))
				}
				expected := int(tc["expected"].(float64))
				got := fn.(func([]int) int)(input)
				if got == expected {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "21":
			for idx, tc := range tests {
				l1Iface := tc["l1"].([]interface{})
				l2Iface := tc["l2"].([]interface{})
				l1 := buildList(l1Iface)
				l2 := buildList(l2Iface)
				expectedIface := tc["expected"].([]interface{})
				expected := buildList(expectedIface)
				got := fn.(func(*ListNode, *ListNode) *ListNode)(l1, l2)
				if compareLists(got, expected) {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "42":
			for idx, tc := range tests {
				inputIface := tc["input"].([]interface{})
				input := make([]int, len(inputIface))
				for i, v := range inputIface {
					input[i] = int(v.(float64))
				}
				expected := int(tc["expected"].(float64))
				got := fn.(func([]int) int)(input)
				if got == expected {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "94":
			for idx, tc := range tests {
				vals := tc["tree"].([]interface{})
				root := buildTree(vals)
				expectedIface := tc["expected"].([]interface{})
				expected := make([]int, len(expectedIface))
				for i, v := range expectedIface {
					expected[i] = int(v.(float64))
				}
				got := fn.(func(*TreeNode) []int)(root)
				if compareSlices(got, expected) {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "104":
			for idx, tc := range tests {
				vals := tc["tree"].([]interface{})
				root := buildTree(vals)
				expected := int(tc["expected"].(float64))
				got := fn.(func(*TreeNode) int)(root)
				if got == expected {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "110":
			for idx, tc := range tests {
				vals := tc["tree"].([]interface{})
				root := buildTree(vals)
				expected := tc["expected"].(bool)
				got := fn.(func(*TreeNode) bool)(root)
				if got == expected {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "424":
			for idx, tc := range tests {
				input := tc["input"].(string)
				k := int(tc["k"].(float64))
				expected := int(tc["expected"].(float64))
				got := fn.(func(string, int) int)(input, k)
				if got == expected {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "438":
			for idx, tc := range tests {
				s := tc["s"].(string)
				p := tc["p"].(string)
				expectedIface := tc["expected"].([]interface{})
				expected := make([]int, len(expectedIface))
				for i, v := range expectedIface {
					expected[i] = int(v.(float64))
				}
				got := fn.(func(string, string) []int)(s, p)
				if reflect.DeepEqual(got, expected) {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		case "567":
			for idx, tc := range tests {
				s1 := tc["s1"].(string)
				s2 := tc["s2"].(string)
				expected := tc["expected"].(bool)
				got := fn.(func(string, string) bool)(s1, s2)
				if got == expected {
					caseResults[idx] = "Pass"
					caseIndices = append(caseIndices, idx+1)
				} else {
					caseResults[idx] = "Fail"
					ok = false
					caseIndices = append(caseIndices, idx+1)
				}
			}
		default:
			caseResults[0] = "NoRunner"
			ok = false
		}
		result := "Pass"
		for _, r := range caseResults {
			if r != "Pass" {
				result = "Fail"
				break
			}
		}
		desc := problemDescriptions[probNum]
		if desc == "" {
			desc = "?"
		}
		summary = append(summary, summaryRow{probNum, desc, probTest.Category, result, caseIndices})
		if !ok {
			allOk = false
		}
	}

	fmt.Printf("%-4s %-25s %-15s %-6s %s\n", "No", "Description", "Category", "Result", "Cases")
	for _, row := range summary {
		fmt.Printf("%-4s %-25s %-15s %-6s %v\n", row.Num, row.Description, row.Category, row.Result, row.Cases)
	}

	return allOk
}

// Helper functions for ListNode
func buildList(vals []interface{}) *ListNode {
	if len(vals) == 0 {
		return nil
	}
	head := &ListNode{Val: int(vals[0].(float64))}
	cur := head
	for _, v := range vals[1:] {
		cur.Next = &ListNode{Val: int(v.(float64))}
		cur = cur.Next
	}
	return head
}

func listToSlice(head *ListNode) []int {
	var res []int
	for head != nil {
		res = append(res, head.Val)
		head = head.Next
	}
	return res
}

func compareLists(l1, l2 *ListNode) bool {
	for l1 != nil && l2 != nil {
		if l1.Val != l2.Val {
			return false
		}
		l1 = l1.Next
		l2 = l2.Next
	}
	return l1 == nil && l2 == nil
}

// Helper to build a binary tree from a LeetCode-style level-order list
func buildTree(vals []interface{}) *TreeNode {
	if len(vals) == 0 || vals[0] == nil {
		return nil
	}
	nodes := make([]*TreeNode, len(vals))
	for i, v := range vals {
		if v == nil {
			nodes[i] = nil
		} else {
			nodes[i] = &TreeNode{Val: int(v.(float64))}
		}
	}
	childIdx := 1
	for i := 0; i < len(vals); i++ {
		if nodes[i] == nil {
			continue
		}
		if childIdx < len(vals) {
			nodes[i].Left = nodes[childIdx]
			childIdx++
		}
		if childIdx < len(vals) {
			nodes[i].Right = nodes[childIdx]
			childIdx++
		}
	}
	return nodes[0]
}

// Helper to compare slices
func compareSlices(a, b []int) bool {
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

func openTestcasesFile() (*os.File, error) {
	repoRoot := os.Getenv("REPO_ROOT")
	if repoRoot != "" {
		f, err := os.Open(repoRoot + "/testcases.json")
		if err == nil {
			return f, nil
		}
	}
	return os.Open("testcases.json")
}
