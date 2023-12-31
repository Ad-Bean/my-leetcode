#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个字符串 date ，按 YYYY-MM-DD 格式表示一个 现行公元纪年法 日期。返回该日期是当年的第几天。
 */

class Solution {
 public:
  int dayOfYear(string date) {
    int year = stoi(date.substr(0, 4)), month = stoi(date.substr(5, 2)), day = stoi(date.substr(8, 2));
    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
      months[1]++;
    }
    int ans = 0;
    for (int i = 0; i < month - 1; i++) {
      ans += months[i];
    }
    return ans + day;
  }
};
int main() {

  Solution test;
  return 0;
}
