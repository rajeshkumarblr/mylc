#include <vector>
#include <mutex>

using namespace std;

class HitCounter {
private:
  vector<int> times;
  vector<int> hits;
  mutex mtx;

public:
  HitCounter() : times(300, 0), hits(300, 0) {}

  void hit(int timestamp) {
    lock_guard<mutex> lock(mtx);
    int idx = timestamp % 300;
    
    // If the bucket holds a timestamp from a previous 5-minute cycle, reset it
    if (times[idx] != timestamp) {
      times[idx] = timestamp;
      hits[idx] = 1;
    } else {
      hits[idx]++;
    }
  }

  int getHits(int timestamp) {
    lock_guard<mutex> lock(mtx);
    int total = 0;
    
    // Scan all 300 buckets (representing the last 300 seconds)
    for (int i = 0; i < 300; ++i) {
      if (timestamp - times[i] < 300) {
        total += hits[i];
      }
    }
    return total;
  }
};
