#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution {
 public:
  int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
    int cnt_a = 0;
    if (a == e && b == f) {
      cnt_a = 0;
    } else if (a == e || b == f) {
      // 象是否在车的路径上，向右向左向下向上挡住
      if (((a == c && a == e) && ((b < d && d < f) || (f < d && d < b))) ||
          ((b == d && b == f) && ((e < c && c < a) || (a < c && c < e)))) {
        cnt_a = 2;
      } else {
        cnt_a = 1;
      }
    } else {
      cnt_a = 2;
    }

    int cnt_b = 0;
    if (c == e) {
      cnt_b = 2;
    } else if (abs(1.0 * (f - d) / (e - c)) == 1.0) {
      // 车是否在象到皇的路线上
      if (e != a && (f - d) / (e - c) == (f - b) / (e - a)) {
        if (((c < a && a < e) && (d < b && b < f)) || ((e < a && a < c) && (f < b && b < d)) ||
            ((c < a && a < e) && (f < b && b < d)) || ((e < a && a < c) && (d < b && b < f))) {
          cnt_b = 3;
        } else {
          cnt_b = 1;
        }
      } else {
        cnt_b = 1;
      }
    } else {
      cnt_b = 2;
    }
    cout << cnt_a << " " << cnt_b << endl;
    return min(cnt_a, cnt_b);
  }
};
int main() {

  Solution test;
  //   cout << test.minMovesToCaptureTheQueen(4, 3, 3, 4, 2, 5) << endl;
  //   cout << test.minMovesToCaptureTheQueen(4, 3, 3, 4, 5, 2) << endl;
  //   cout << test.minMovesToCaptureTheQueen(4, 5, 6, 8, 2, 1) << endl;
  cout << test.minMovesToCaptureTheQueen(7, 4, 7, 5, 7, 3) << endl;
  return 0;
}