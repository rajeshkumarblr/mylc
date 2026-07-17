#include <set>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <nlohmann/json.hpp>
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <mutex>
#include <thread>
#include <queue>
#include <condition_variable>
using namespace std;
using json = nlohmann::json;

bool lc_test_1242(const json &j);

using json = nlohmann::json;

bool lc_test_1242(const json &j);

using json = nlohmann::json;

bool lc_test_1242(const json &j);

using json = nlohmann::json;

bool lc_test_1242(const json &j);

using json = nlohmann::json;

vector<string> runWebCrawler(const vector<string>& urls, const vector<vector<int>>& edges, const string& startUrl);



// @lc code=start
// This is the HtmlParser's API interface.
// You should not implement it, or speculate about its implementation
class HtmlParser {
private:
  unordered_map<string, vector<string>> adj;
public:
  HtmlParser() {}
  HtmlParser(const unordered_map<string, vector<string>>& graph) : adj(graph) {}

  vector<string> getUrls(string url) const {
    auto it = adj.find(url);
    if (it != adj.end()) {
      return it->second;
    }
    return {};
  }
};

class Solution {
private:
  string getHostname(const string& url) {
    size_t pos = url.find("//");
    if (pos == string::npos) return "";
    size_t start = pos + 2;
    size_t end = url.find('/', start);
    if (end == string::npos) {
      return url.substr(start);
    }
    return url.substr(start, end - start);
  }

public:
  vector<string> crawl(string startUrl, HtmlParser htmlParser) {
    string hostname = getHostname(startUrl);

    mutex mtx;
    condition_variable cv;
    queue<string> q;
    unordered_set<string> visited;
    int active_workers = 0;
    bool done = false;

    q.push(startUrl);
    visited.insert(startUrl);

    auto worker = [&]() {
      while (true) {
        string url;
        {
          unique_lock<mutex> lock(mtx);
          while (q.empty() && !done) {
            cv.wait(lock);
          }
          if (done) {
            return;
          }
          url = q.front();
          q.pop();
          active_workers++;
        }

        vector<string> next_urls = htmlParser.getUrls(url);

        {
          unique_lock<mutex> lock(mtx);
          active_workers--;

          for (const string& next_url : next_urls) {
            if (getHostname(next_url) == hostname) {
              if (visited.insert(next_url).second) {
                q.push(next_url);
              }
            }
          }

          if (q.empty() && active_workers == 0) {
            done = true;
            cv.notify_all();
            return;
          } else if (!q.empty()) {
            cv.notify_all();
          }
        }
      }
    };

    int num_threads = 4;
    vector<thread> threads;
    for (int i = 0; i < num_threads; ++i) {
      threads.emplace_back(worker);
    }

    for (auto& t : threads) {
      t.join();
    }

    return vector<string>(visited.begin(), visited.end());
  }
};
// @lc code=end
















bool lc_test_1242(const json &j) {
  bool all = true;
  size_t idx = 0;
  for (const auto &tc : j.at("cases")) {
    std::vector<std::string> urls = tc.at("urls").get<std::vector<std::string>>();
    std::vector<std::vector<int>> edges = tc.at("edges").get<std::vector<std::vector<int>>>();
    std::string startUrl = tc.at("startUrl").get<std::string>();
    std::vector<std::string> expected = tc.at("expected").get<std::vector<std::string>>();
    
    std::vector<std::string> got = runWebCrawler(urls, edges, startUrl);
    
    std::sort(got.begin(), got.end());
    std::sort(expected.begin(), expected.end());
    
    bool ok = (got == expected);
    if (!ok) {
      std::cout << "  Case " << (++idx) << ": FAIL\n"
                << "    startUrl=\"" << startUrl << "\"\n"
                << "    expected=[";
      for (const auto &u : expected) std::cout << "\"" << u << "\", ";
      std::cout << "]\n    got=[";
      for (const auto &u : got) std::cout << "\"" << u << "\", ";
      std::cout << "]\n";
    } else {
      ++idx;
    }
    all &= ok;
  }
  return all;
}



vector<string> runWebCrawler(const vector<string>& urls,
                             const vector<vector<int>>& edges,
                             const string& startUrl) {
  unordered_map<string, vector<string>> graph;
  for (const auto& edge : edges) {
    if (edge.size() == 2) {
      int u = edge[0];
      int v = edge[1];
      if (u >= 0 && u < (int)urls.size() && v >= 0 && v < (int)urls.size()) {
        graph[urls[u]].push_back(urls[v]);
      }
    }
  }

  HtmlParser parser(graph);
  Solution sol;
  return sol.crawl(startUrl, parser);
}





int main() {
    try {
        nlohmann::json j = nlohmann::json::parse(R"raw({
  "cases": [
    {
      "urls": [
        "http://news.yahoo.com",
        "http://news.yahoo.com/news",
        "http://news.yahoo.com/news/topics/",
        "http://news.google.com",
        "http://news.yahoo.com/us"
      ],
      "edges": [
        [
          2,
          0
        ],
        [
          2,
          1
        ],
        [
          3,
          2
        ],
        [
          3,
          1
        ],
        [
          0,
          4
        ]
      ],
      "startUrl": "http://news.yahoo.com/news/topics/",
      "expected": [
        "http://news.yahoo.com",
        "http://news.yahoo.com/news",
        "http://news.yahoo.com/news/topics/",
        "http://news.yahoo.com/us"
      ]
    }
  ]
})raw");
        return lc_test_1242(j) ? 0 : 1;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return 4;
    }
}
