
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

方法一：排序双指针
此外，如果 s 和 t 的长度不同，t 必然不是 s 的异位词。

方法二：哈希表
26个小写字母，直接遍历

如果是 Unicode 则用 unordered_map
 */
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) {
      return false;
    }
    vector<int> mps(26);
    for (const auto& ss : s) {
      mps[ss - 'a']++;
    }
    for (const auto& tt : t) {
      mps[tt - 'a']--;
      if (mps[tt - 'a'] < 0) {
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