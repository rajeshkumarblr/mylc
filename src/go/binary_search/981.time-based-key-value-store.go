package main

/*
 * @lc app=leetcode id=981 lang=golang
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start

type Entry struct {
	timestamp int
	value     string
}

type TimeMap struct {
	// A Go map where the value is a slice of Entry structs
	store map[string][]Entry
}

func Constructor() TimeMap {
	return TimeMap{
		store: make(map[string][]Entry),
	}
}

// O(1) amortized insertion
func (this *TimeMap) Set(key string, value string, timestamp int) {
	// Go automatically handles appending to nil slices if the key doesn't exist yet
	this.store[key] = append(this.store[key], Entry{timestamp: timestamp, value: value})
}

// O(log N) manual binary search
func (this *TimeMap) Get(key string, timestamp int) string {
	records, exists := this.store[key]
	if !exists {
		return ""
	}

	left := 0
	right := len(records) - 1
	result := ""

	// The exact same binary search logic as C++
	for left <= right {
		mid := left + (right-left)/2 // Prevents integer overflow

		if records[mid].timestamp <= timestamp {
			// Valid candidate found. Save it and search right.
			result = records[mid].value
			left = mid + 1
		} else {
			// Too large. Search left.
			right = mid - 1
		}
	}

	return result
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Set(key,value,timestamp);
 * param_2 := obj.Get(key,timestamp);
 */
// @lc code=end

func runTimeMap(commands []string, args [][]interface{}) []interface{} {
	var obj TimeMap
	var res []interface{}
	for i, cmd := range commands {
		if cmd == "TimeMap" {
			obj = Constructor()
			res = append(res, nil)
		} else if cmd == "set" {
			obj.Set(args[i][0].(string), args[i][1].(string), int(args[i][2].(float64)))
			res = append(res, nil)
		} else if cmd == "get" {
			val := obj.Get(args[i][0].(string), int(args[i][1].(float64)))
			res = append(res, val)
		}
	}
	return res
}
