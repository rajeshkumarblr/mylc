package main

import (
	"encoding/json"
	"fmt"
	"os"
)

var solutionRegistry = map[string]func([]int) int{
	"trapTwoPointer": trapTwoPointer,
	"trapMinMax":     trapMinMax,
	// Add more functions here
}

func main() {
	// Read test data from file (e.g., testcases.json)
	file, err := os.Open("testcases.json")
	if err != nil {
		fmt.Println("Error opening testcases.json:", err)
		os.Exit(1)
	}
	defer file.Close()

	var tests []struct {
		Func     string `json:"func"`
		Input    []int  `json:"input"`
		Expected int    `json:"expected"`
	}
	if err := json.NewDecoder(file).Decode(&tests); err != nil {
		fmt.Println("Error decoding testcases:", err)
		os.Exit(1)
	}

	ok := true
	for idx, tc := range tests {
		fn, found := solutionRegistry[tc.Func]
		if !found {
			fmt.Printf("Function %s not found\n", tc.Func)
			ok = false
			continue
		}
		got := fn(tc.Input)
		if got != tc.Expected {
			fmt.Printf("FAIL at case %d: func=%s got=%d want=%d\n", idx, tc.Func, got, tc.Expected)
			ok = false
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
