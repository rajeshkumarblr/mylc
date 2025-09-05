#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <utility>
#include <ostream>
#include <sstream>
#include <iomanip>
using std::vector;
using std::cout;
using std::endl;
using std::map;
using std::pair;

// For vector output
template<typename T>
void print_vector(const vector<T>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]";
}


// Overload operator<< for vector<T>
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i + 1 < v.size()) os << ",";
    }
    os << "]";
    return os;
}

// For Two Sum, where order of indices may not matter
template<typename Input, typename Output, typename Func>
bool run_vector_tests(const std::vector<std::pair<Input, Output>>& tests, Func func) {
    bool all_passed = true;
    for (const auto& [input, expected] : tests) {
        Output result = func(input);
        bool pass = (result == expected) ||
                    (result.size() == 2 && expected.size() == 2 &&
                     result[0] == expected[1] && result[1] == expected[0]);
        cout << "Input: ";
        print_vector(input.first);
        cout << ", target=" << input.second << " | ";
        if (pass) {
            cout << "PASS";
        } else {
            cout << "FAIL (got: ";
            print_vector(result);
            cout << "; expected: ";
            print_vector(expected);
            cout << ")";
            all_passed = false;
        }
        cout << endl;
    }
    return all_passed;
}

// Utility for testing int->bool functions
template<typename Func>
bool run_bool_tests(const std::vector<std::pair<int, bool>>& tests, Func func) {
    bool all_passed = true;
    for (const auto& [input, expected] : tests) {
        bool result = func(input);
        std::cout << "Input: " << input << " | Expected: " << expected << " | Got: " << result << " | ";
        if (result == expected) {
            std::cout << "PASS" << std::endl;
        } else {
            std::cout << "FAIL" << std::endl;
            all_passed = false;
        }
    }
    return all_passed;
}

// Print test result for any comparable type, with aligned columns
template<typename Input, typename Result>
bool print_test_result(const Input& input, const Result& result, const Result& expected) {
    constexpr int input_width = 20;
    constexpr int expected_width = 15;
    constexpr int got_width = 15;

    std::ostringstream oss_input, oss_expected, oss_result;
    oss_input << input;
    oss_expected << expected;
    oss_result << result;

    std::cout << std::left
              << "Input: " << std::setw(input_width) << oss_input.str()
              << " | Expected: " << std::setw(expected_width) << oss_expected.str()
              << " | Got: " << std::setw(got_width) << oss_result.str()
              << " | ";

    bool res = (result == expected);
    std::cout << (res ? "PASS" : "FAIL") << std::endl;
    return res;
}
