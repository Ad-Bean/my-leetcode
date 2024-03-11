#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/* 
给你一个字符串 title ，它由单个空格连接一个或多个单词组成，
每个单词都只包含英文字母。请你按以下规则将每个单词的首字母 大写 ：

如果单词的长度为 1 或者 2 ，所有字母变成小写。
否则，将单词首字母大写，剩余字母变成小写。
请你返回 大写后 的 title 。

 
示例 1：

输入：title = "capiTalIze tHe titLe"
输出："Capitalize The Title"
解释：
由于所有单词的长度都至少为 3 ，将每个单词首字母大写，剩余字母变为小写。

方法一：遍历
用空格分割字符串，然后遍历每个单词，如果长度大于 2 ，则首字母大写，剩余字母小写，否则全部小写。

注意细节：更新 l

cpp 可以使用 istringstream 来分割字符串
 */
class Solution {
 public:
  string capitalizeTitle(string title) {
    int n = title.size();
    int l = 0;
    for (int r = 0; r <= n; r++) {
      if (r == n || title[r] == ' ') {
        if (r - l > 2) {
          title[l] = toupper(title[l]);
          while (l++ < r) {
            title[l] = tolower(title[l]);
          }
        } else {
          while (l < r) {
            title[l] = tolower(title[l]);
            l++;
          }
          l++;
        }
      }
    }
    return title;
  }
};
int main() {

  Solution test;
  //   cout << test.capitalizeTitle("capiTalIze tHe titLe") << endl;
  cout << test.capitalizeTitle("First leTTeR of EACH woRd") << endl;
  //   cout << test.capitalizeTitle("IUz g OM") << endl;
  return 0;
}
