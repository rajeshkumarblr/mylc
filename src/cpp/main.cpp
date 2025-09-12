#include "lc_test_utils.h"

using json = nlohmann::json;
using namespace std;

static optional<json> load_testcases() {
    const char* paths[] = {
        "/home/rajesh/lc/testcases.json",
        "../../testcases.json"
        "../testcases.json", // REPO_ROOT from src/cpp
        "testcases.json",    // REPO_ROOT if run from root
        "src/testcases.json",
        "src/cpp/testcases.json",
        "src/go/testcases.json"
    };
    for (auto p : paths) {
        ifstream in(p);
        if (in.good()) { json j; in >> j; return j; }
    }
    return nullopt;
}

int main(int, char**) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto tj = load_testcases();
    if (!tj) {
        cerr << "Could not find testcases.json (searched src)\n";
        return 2;
    }
    json tests = *tj;

    // Get problem number from env or default to 1
    string prob = "1";
    if (const char* s = getenv("NUM")) prob = s;

    // Map of supported problems to their handler functions
    const std::vector<int> solved = {1, 2, 3, 9, 11, 21, 42, 94, 104, 110, 424, 438, 567};
    using TestFn = bool(*)(const json&);
    std::map<int, TestFn> handlers = {
        {1,  lc_test_1},
        {2,  lc_test_2},
        {3,  lc_test_3},
        {9,  lc_test_9},
        {11, lc_test_11},
        {21, lc_test_21},
        {42, lc_test_42},
        {94, lc_test_94},
        {104, lc_test_104},
        {110, lc_test_110},
        {424, lc_test_424},
        {438, lc_test_438},
        {567, lc_test_567}
    };

    if (prob == "all") {
        int failures = 0;
        for (int prob_num : solved) {
            string key = to_string(prob_num);
            if (!tests.contains(key)) {
                cout << "No testcases for problem " << key << ".\n";
                failures++;
                continue;
            }
            string desc = tests.at(key).contains("description") ? tests.at(key).at("description").get<string>() : "";
            cout << "=== LC " << key << ": " << desc << " ===\n";
            bool ok = handlers[prob_num](tests.at(key));
            cout << (ok ? "Result: PASS\n" : "Result: FAIL\n");
            if (!ok) failures++;
        }
        return failures == 0 ? 0 : 1;
    }

    if (!tests.contains(prob)) {
        cout << "No testcases for problem " << prob << ".\n";
        return 0;
    }

    bool ok = false;
    int prob_num = 0;
    try {
        prob_num = stoi(prob);
    } catch (...) {
        cout << "Invalid problem number: " << prob << "\n";
        return 1;
    }
    string desc = tests.at(prob).contains("description") ? tests.at(prob).at("description").get<string>() : "";
    cout << "=== LC " << prob << ": " << desc << " ===\n";
    if (handlers.count(prob_num)) {
        ok = handlers[prob_num](tests.at(prob));
    } else {
        cout << "No runner for problem " << prob << ".\n";
        return 1;
    }
    cout << (ok ? "Result: PASS\n" : "Result: FAIL\n");
    return ok ? 0 : 1;
}
