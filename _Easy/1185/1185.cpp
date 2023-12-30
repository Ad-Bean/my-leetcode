#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给你一个日期，请你设计一个算法来判断它是对应一周中的哪一天。

输入为三个整数：day、month 和 year，分别表示日、月、年。

您返回的结果必须是这几个值中的一个 {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}。

给出的日期一定是在 1971 到 2100 年之间的有效日期。

方法一：模拟
1970 年 12 月 31 日 是星期四

 */
class Solution {
 public:
  string dayOfTheWeek(int day, int month, int year) {
    // 1970 年 12 月 31 日 是星期四
    vector<string> weekdays = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};
    vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // 本年前一年，共过了多少天, 1970 不是闰年, 1968是闰年
    int days = 365 * (year - 1 - 1970) + (year - 1 - 1968) / 4;
    for (int i = 0; i < month - 1; i++) {
      days += months[i];
    }
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
      // 本年是闰年且大于三月
      if (month >= 3) {
        days += 1;
      }
    }
    return week[(days + day) % 7];
  }
};
int main() {

  Solution test;
  return 0;
}
