#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
 public:
  int distributeCandies(int n, int limit) {
    int count = 0;

    for (int i = 0; i <= limit; ++i) {
      for (int j = 0; j <= limit; ++j) {
        for (int k = 0; k <= limit; ++k) {
          if (i + j + k == n) {
            count++;
            // cout << i << " " << j << " " << k << endl;
          }
        }
      }
    }

    return count;
  }
};
int main() {
  Solution test;
  cout << test.distributeCandies(11, 1) << endl;
  cout << test.distributeCandies(11, 2) << endl;
  cout << test.distributeCandies(11, 3) << endl;
  cout << test.distributeCandies(11, 4) << endl;
  cout << test.distributeCandies(11, 5) << endl;
  cout << test.distributeCandies(11, 6) << endl;
  cout << test.distributeCandies(11, 7) << endl;
  cout << test.distributeCandies(11, 8) << endl;
  cout << test.distributeCandies(11, 9) << endl;
  cout << test.distributeCandies(11, 10) << endl;
  cout << test.distributeCandies(11, 11) << endl;
  return 0;
}
// total: C(n + 2, 2)
// n= 1 total =  3: 3
// n= 2 total =  6: 3, 6                                          3
// n= 3 total = 10: 1, 7, 10                                      6  3
// n= 4 total = 15: 0, 6, 12, 15                                  6  6  3
// n= 5 total = 21: 0, 3, 12, 18, 21                              3  9  6  3
// n= 6 total = 28: 0, 1, 10, 19, 25, 28                          1  9  9  6  3
// n= 7 total = 36: 0, 0,  6, 18, 27, 33, 36                      0  6 12  9  6  3
// n= 8 total = 45: 0, 0,  3, 15, 27, 36, 42, 45                  0  3 12 12  9  6  3
// n= 9 total = 55: 0, 0,  1, 10, 25, 37, 46, 52, 55              0  1  9 15 12  9  6  3
// n=10 total = 66: 0, 0,  0,  6, 21, 36, 48, 57, 63, 66          0  0  6 15 15 12  9  6  3
// n=11 total = 78: 0, 0,  0,  3, 15, 33, 48, 60, 69, 75, 78      0  0  3 12 18 15 12  9  6  3

/*
  an = (n+2)*(n+1)/2
  d = 3
  for (i = n; i >= n / 2; i-- ){
    ai = a[i+1]- d 
    d+=3
  }
7 5
36 - (3 + 6)
((3 + 3 * (7-5-1)) + 3 ) * (7-5) / 2
*/