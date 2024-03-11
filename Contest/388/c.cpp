#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 

时间复杂度 O(length ^ 2 * n *m * (n + m)) 就算 KMP 也超时

由于子串要求最短且不是其他 arr 中的子字符串
 */
class Solution {
  int strStr(string haystack, string needle) {
    int n = haystack.size(), m = needle.size();
    vector<int> next;
    next.emplace_back(0);
    int i = 1, len = 0;  // 下标和最长共同前后缀
    while (i < m) {
      if (needle[i] == needle[len]) {
        next.emplace_back(++len);
        i++;
      } else {
        if (len == 0) {
          i++;
          next.emplace_back(0);
        } else {
          len = next[len - 1];
        }
      }
    }

    int j = 0;
    i = 0;
    while (i < n) {
      if (haystack[i] == needle[j]) {
        i++, j++;
      } else if (j > 0) {
        j = next[j - 1];
      } else {
        i++;
      }
      if (j == m) {
        return i - j;
      }
    }
    return -1;
  }

 public:
  vector<string> shortestSubstrings(vector<string>& arr) {
    vector<string> ans;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      string s = arr[i];
      string sub = "";
      int m = s.size();

      for (int j = 0; j < m; j++) {
        for (int k = j; k < m; k++) {
          string curSub = s.substr(j, k - j + 1);  // 当前 arr[i] 的子串
          // 如果当前子串字典序比 sub 大，则忽略
          if (sub != "" && (curSub.size() > sub.size() || (curSub.size() == sub.size() && curSub > sub))) {
            break;
          }
          if (sub == "" || curSub.size() < sub.size() || (sub.size() == curSub.size() && curSub < sub)) {
            bool flag = true;
            for (int l = 0; l < n; l++) {
              if (l == i) {
                continue;
              }
              if (strStr(arr[l], curSub) != -1) {
                flag = false;  // 是其他的子串
                break;
              }
            }
            if (flag) {
              sub = curSub;
            }
          }
        }
      }
      ans.emplace_back(sub);
    }
    return ans;
  }
};

int main() {

  Solution test;
  vector<string> a = {"gfnt", "xn", "mdz", "yfmr", "fi", "wwncn", "hkdy"};

  auto ans = test.shortestSubstrings(a);
  for (const auto& s : ans) {
    cout << s << " ";
  }
  cout << endl;
  return 0;
}