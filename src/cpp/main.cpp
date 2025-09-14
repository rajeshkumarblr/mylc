#include "lc_test_utils.h"

using json = nlohmann::json;
using namespace std;

static optional<json> load_testcases() {
    string path = get_testcases_json_path();
    ifstream in(path);
    if (in.good()) { json j; in >> j; return j; }
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
    string category = "";
    if (const char* s = getenv("LC_PROB_NUM")) prob = s;
    if (const char* c = getenv("LC_CATEGORY")) category = c;

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

    // If LC_PROB_NUM is "all" or LC_CATEGORY is set, run all problems (summary table)
    if (prob == "all" || !category.empty()) {
        struct SummaryRow {
            string num, desc, category, result;
            vector<int> cases;
        };
        vector<SummaryRow> summary;
        int failures = 0;
        int matched = 0;
        for (int prob_num : solved) {
            string key = to_string(prob_num);
            if (!tests.contains(key)) {
                summary.push_back({key, "", "", "NoTest", {}});
                failures++;
                continue;
            }
            const auto& test = tests.at(key);
            string desc = test.contains("description") ? test.at("description").get<string>() : "";
            string cat = test.contains("category") ? test.at("category").get<string>() : "";
            if (!category.empty() && cat != category) continue;
            matched++;
            vector<int> case_indices;
            if (test.contains("cases")) {
                int idx = 1;
                for (size_t i = 0; i < test.at("cases").size(); ++i) case_indices.push_back(idx++);
            }
            bool ok = handlers[prob_num](test);
            summary.push_back({key, desc, cat, ok ? "Pass" : "Fail", case_indices});
            if (!ok) failures++;
        }
        if (!category.empty() && matched == 0) {
            cout << "No solved problems matched category '" << category << "'.\n";
            return 4; // distinct exit for empty category
        }
        cout << left << setw(5) << "No" << setw(28) << "Description" << setw(16) << "Category" << setw(7) << "Result" << "Cases" << endl;
        for (const auto& row : summary) {
            cout << left << setw(5) << row.num
                 << setw(28) << row.desc.substr(0,27)
                 << setw(16) << row.category
                 << setw(7) << row.result
                 << "[";
            for (size_t i = 0; i < row.cases.size(); ++i) {
                if (i) cout << " ";
                cout << row.cases[i];
            }
            cout << "]\n";
        }
        cout << "Final Result: " << (failures == 0 ? "PASS yes" : "FAIL") << endl;
        return failures == 0 ? 0 : 1;
    }

    // Otherwise, run a single problem
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
