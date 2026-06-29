#include <string>
#include <vector>
#include <unordered_set>
#include <mutex>
#include <thread>
#include <queue>
#include <condition_variable>

using namespace std;

// Interface provided by the problem
class HtmlParser {
public:
  vector<string> getUrls(string url) const;
};

class Solution {
private:
  // Extracts the hostname from a given URL
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

    // Seed the crawler
    q.push(startUrl);
    visited.insert(startUrl);

    // Worker thread function
    auto worker = [&]() {
      while (true) {
        string url;
        {
          unique_lock<mutex> lock(mtx);
          // Wait for work or exit signal
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

        // Fetch URLs concurrently (unlock block to run parser in parallel)
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

          // Termination condition: no pending tasks in queue and no threads processing
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

    // Spawn thread pool
    int num_threads = 4;
    vector<thread> threads;
    for (int i = 0; i < num_threads; ++i) {
      threads.emplace_back(worker);
    }

    // Await execution completion
    for (auto& t : threads) {
      t.join();
    }

    return vector<string>(visited.begin(), visited.end());
  }
};
