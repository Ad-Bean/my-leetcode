#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
你在和朋友一起玩 猜数字（Bulls and Cows）游戏，该游戏规则如下：

写出一个秘密数字，并请朋友猜这个数字是多少。朋友每猜测一次，你就会给他一个包含下述信息的提示：

猜测数字中有多少位属于数字和确切位置都猜对了（称为 "Bulls"，公牛），
有多少位属于数字猜对了但是位置不对（称为 "Cows"，奶牛）。也就是说，这次猜测中有多少位非公牛数字可以通过重新排列转换成公牛数字。
给你一个秘密数字 secret 和朋友猜测的数字 guess ，请你返回对朋友这次猜测的提示。

提示的格式为 "xAyB" ，x 是公牛个数， y 是奶牛个数，A 表示公牛，B 表示奶牛。

请注意秘密数字和朋友猜测的数字都可能含有重复数字。

1 <= secret.length, guess.length <= 1000
secret.length == guess.length
secret 和 guess 仅由数字组成

输入：secret = "1807", guess = "7810"
输出："1A3B"
解释：数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
"1807"
  |
"7810"

方法一：哈希表
统计 secret 中每个数字出现的次数
遍历 guess 如果该位置一样，则 x++ 同时 cnt[guess[i]]--
如果位置不一样，但是 cnt[guess[i]] > 0 则 y++ 并且 cnt[guess[i]]--


由于数字只有 0-9 用长度为 10 的数组来替代哈希表

注意：如果这样写，要先统计 x 再统计 y 两次循环

方法二：一次循环
先统计 secret[i] == guess[i] 的个数 x，如果不相等就更新 cnt1[secret[i]] 和 cnt2[guess[i]]
然后遍历 0-9 找最小的 min(cnt1[i], cnt2[i]) 加到 y 上
 */
class Solution {
 public:
  string getHint(string secret, string guess) {
    int cnt[10] = {0};
    for (const auto& c : secret) {
      cnt[c - '0']++;
    }
    int n = guess.size();
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
      if (guess[i] == secret[i]) {
        x++;
        cnt[guess[i] - '0']--;
      }
    }
    for (int i = 0; i < n; i++) {
      if (guess[i] != secret[i] && cnt[guess[i] - '0'] > 0) {
        cnt[guess[i] - '0']--;
        y++;
      }
    }
    return to_string(x) + "A" + to_string(y) + "B";
  }
};
int main() {

  Solution test;
  string secret = "1122", guess = "1222";
  cout << test.getHint(secret, guess) << endl;
  return 0;
}
