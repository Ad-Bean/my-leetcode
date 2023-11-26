#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
n 个二进制字符串（数），找不存在的
即从 [0, 2^n - 1] 找不存在的

转成整数：stoi(num, nullptr, 2)
用 set 存入之后枚举

康托对角线：
只要和第 i 个串下标 i 的字符 nums[i][i] 不同，构造出来的串就和所有的串都不同。
 */
class Solution {
 public:
  string findDifferentBinaryString(vector<string>& nums) {
    string ans;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i][i] == '0') {
        ans += '1';
      } else {
        ans += '0';
      }
    }

    return ans;
  }
};
int main() {

  Solution test;
  vector<string> nums{"01", "10"};
  cout << test.findDifferentBinaryString(nums) << endl;
  return 0;
}