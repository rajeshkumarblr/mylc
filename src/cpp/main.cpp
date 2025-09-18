// src/cpp/main.cpp  — drop-in replacement

#include <algorithm>
#include <iomanip>
#include <map>
#include <string>
#include "lc_test_utils.h"

using json = nlohmann::json;
using namespace std;

// Load testcases.json via helper declared in lc_test_utils.h/cpp
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

    // Inputs via env
    string prob = "1";
    string category = "";
    if (const char* s = getenv("LC_PROB_NUM")) prob = s;
    if (const char* c = getenv("LC_CATEGORY")) category = c;

    // Supported problems → test functions (drivers are in lc_test_utils.cpp)
    const vector<int> solved = {1, 2, 3, 9, 11, 21, 42, 94, 100, 102, 103, 104, 110, 424, 438, 567, 739};
    using TestFn = bool(*)(const json&);
    map<int, TestFn> handlers = {
        {1,   lc_test_1},
        {2,   lc_test_2},
        {3,   lc_test_3},
        {9,   lc_test_9},
        {11,  lc_test_11},
        {21,  lc_test_21},
        {42,  lc_test_42},
        {94,  lc_test_94},
        {100, lc_test_100},
        {102, lc_test_102},
        {103, lc_test_103},
        {104, lc_test_104},
        {110, lc_test_110},
        {424, lc_test_424},
        {438, lc_test_438},
        {567, lc_test_567},
        {739, lc_test_739}
    };

    auto print_header = [](){
        cout << left << setw(5) << "No"
             << setw(28) << "Description"
             << setw(16) << "Category"
             << setw(7)  << "Result"
             << "Cases\n";
    };

    // -------- ALL/CATEGORY MODE --------
    if (prob == "all" || !category.empty()) {
        struct SummaryRow {
            string num, desc, cat, result;
            vector<int> cases;
        };
        vector<SummaryRow> summary;

        int failures = 0;
        int matchedProblems = 0;

        for (int prob_num : solved) {
            string key = to_string(prob_num);
            if (!tests.contains(key)) {
                // Problem in runner but no tests in JSON
                summary.push_back({key, "", "", "NoTest", {}});
                failures++;
                continue;
            }
            const auto& test = tests.at(key);
            string desc = test.contains("description") ? test.at("description").get<string>() : "";
            string cat  = test.contains("category")    ? test.at("category").get<string>()    : "";

            if (!category.empty() && cat != category) continue;
            matchedProblems++;

            // Pre-compute case indices to show which cases ran
            vector<int> case_indices;
            if (test.contains("cases")) {
                case_indices.reserve(test.at("cases").size());
                for (int i = 1; i <= static_cast<int>(test.at("cases").size()); ++i) case_indices.push_back(i);
            }

            bool ok = false;
            auto it = handlers.find(prob_num);
            if (it != handlers.end()) {
                ok = it->second(test);
            } else {
                // Runner missing
                summary.push_back({key, desc, cat, "NoRunner", {}});
                failures++;
                continue;
            }

            summary.push_back({key, desc, cat, ok ? "Pass" : "Fail", case_indices});
            if (!ok) failures++;
        }

        if (!category.empty() && matchedProblems == 0) {
            cout << "No solved problems matched category '" << category << "'.\n";
            return 4;
        }

        // Sort rows by numeric problem number
        sort(summary.begin(), summary.end(), [](const SummaryRow& a, const SummaryRow& b){
            return stoi(a.num) < stoi(b.num);
        });

        // Print table
        print_header();

        int totalCases = 0, passedProblems = 0;
        for (const auto& row : summary) {
            cout << left << setw(5)  << row.num
                 << setw(28) << (row.desc.size() > 27 ? row.desc.substr(0,27) : row.desc)
                 << setw(16) << row.cat
                 << setw(7)  << row.result
                 << "[";
            for (size_t i = 0; i < row.cases.size(); ++i) {
                if (i) cout << " ";
                cout << row.cases[i];
            }
            cout << "]\n";

            totalCases += static_cast<int>(row.cases.size());
            if (row.result == "Pass") passedProblems++;
        }

        int failedProblems = static_cast<int>(summary.size()) - passedProblems;
        cout << "\nSummary: problems=" << summary.size()
             << ", passed=" << passedProblems
             << ", failed=" << failedProblems
             << ", total_cases=" << totalCases << "\n";

        cout << "Final Result: " << (failures == 0 ? "PASS yes" : "FAIL") << endl;
        return failures == 0 ? 0 : 1;
    }

    // -------- SINGLE PROBLEM MODE --------
    if (!tests.contains(prob)) {
        cout << "No testcases for problem " << prob << ".\n";
        return 0;
    }

    int prob_num = 0;
    try { prob_num = stoi(prob); }
    catch (...) { cout << "Invalid problem number: " << prob << "\n"; return 1; }

    const auto &test = tests.at(prob);
    string desc = test.contains("description") ? test.at("description").get<string>() : "";
    string cat  = test.contains("category")    ? test.at("category").get<string>()    : "";

    bool ok = false;
    if (handlers.count(prob_num)) {
        ok = handlers[prob_num](test);
    } else {
        cout << "No runner for problem " << prob << ".\n";
        return 1;
    }

    // Case indices for the single row
    vector<int> case_indices;
    if (test.contains("cases")) {
        case_indices.reserve(test.at("cases").size());
        for (int i = 1; i <= static_cast<int>(test.at("cases").size()); ++i) case_indices.push_back(i);
    }

    print_header();
    cout << left << setw(5)  << prob
         << setw(28) << (desc.size() > 27 ? desc.substr(0,27) : desc)
         << setw(16) << cat
         << setw(7)  << (ok ? "Pass" : "Fail")
         << "[";
    for (size_t i = 0; i < case_indices.size(); ++i) {
        if (i) cout << " ";
        cout << case_indices[i];
    }
    cout << "]\n";

    cout << "\nSummary: problems=1, passed=" << (ok ? 1 : 0)
         << ", failed=" << (ok ? 0 : 1)
         << ", total_cases=" << case_indices.size() << "\n";

    cout << "Final Result: " << (ok ? "PASS yes" : "FAIL") << endl;
    return ok ? 0 : 1;
}
