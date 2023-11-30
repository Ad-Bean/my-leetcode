
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
两个字符串是否接近
1. 可以交换 words1[i] 和 words1[j]
2. words1 可以和 words2 中进行某个字符交换，出现次数必须一致

首先记数
对 1 需要保证两个字符串中的 字符 出现次数一致
对 2 需要保证两个字符串中的 字符 排序后大小一致，所以可以任意交换

 */
class Solution {
 public:
  bool closeStrings(string word1, string word2) {
    int cnt1[26] = {};
    int cnt2[26] = {};
    for (const char& c : word1) {
      cnt1[c - 'a']++;
    }
    for (const char& c : word2) {
      cnt2[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
      if (cnt1[i] == 0 && cnt2[i] != 0) {
        return false;
      } else if (cnt1[i] != 0 && cnt2[i] == 0) {
        return false;
      }
    }
    sort(cnt1, cnt1 + 26);
    sort(cnt2, cnt2 + 26);
    for (int i = 0; i < 26; i++) {
      if (cnt1[i] != cnt2[i]) {
        return false;
      }
    }
    return true;
  }
};

int main() {

  Solution test;
  return 0;
}