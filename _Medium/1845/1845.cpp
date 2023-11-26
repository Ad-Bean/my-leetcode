#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
 *   heap sort
 */
class SeatManager {
  vector<int> seats;

 public:
  SeatManager(int n) {
    // min heap
    for (int i = 1; i <= n; i++) {
      seats.emplace_back(i);
    }
  }

  int reserve() {
    pop_heap(seats.begin(), seats.end(), greater<int>());  // pop first and shift the first to the end
    int tmp = seats.back();
    seats.pop_back();
    return tmp;
  }

  void unreserve(int seatNumber) {
    seats.emplace_back(seatNumber);
    push_heap(seats.begin(), seats.end(), greater<int>());
  }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * 
 * 
 * 
 */
int main() {
  SeatManager* obj = new SeatManager(5);
  int param_1 = obj->reserve();
  obj->unreserve(1);
  cout << " param_1 " << param_1 << endl;
  return 0;
}