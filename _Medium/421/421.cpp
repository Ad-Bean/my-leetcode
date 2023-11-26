#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 

由于数组中的元素都在 [0,2^31)的范围内
那么我们可以将每一个数表示为一个长度为 31 位的二进制数（如果不满 31 位，在最高位之前补上若干个前导 0 即可）；

如果我们将字符串放入字典树中，那么在字典树中查询一个字符串的过程，恰好就是从高位开始确定每一个二进制位的过程
 */

struct Trie {
  // left 1, right 0
  Trie* left = nullptr;
  Trie* right = nullptr;
  Trie() {}
};
class Solution {
  Trie* root = new Trie();

 public:
  void add(int num) {
    Trie* cur = root;
    for (int k = 30; k >= 0; k--) {
      int bit = (num >> k) & 1;
      if (bit == 1) {
        if (!cur->left) {
          cur->left = new Trie();
        }
        cur = cur->left;
      } else if (bit == 0) {
        if (!cur->right) {
          cur->right = new Trie();
        }
        cur = cur->right;
      }
    }
  }

  int check(int num) {
    Trie* cur = root;
    int x = 0;
    for (int k = 30; k >= 0; k--) {
      int bit = (num >> k) & 1;
      if (bit == 1) {
        if (cur->left) {
          cur = cur->left;
          x = x * 2 + 1;
        } else {
          cur = cur->right;
          x *= 2;
        }
      } else if (bit == 0) {
        if (cur->right) {
          cur = cur->right;
          x = x * 2 + 1;
        } else {
          cur = cur->left;
          x *= 2;
        }
      }
    }
    return x;
  }

  int findMaximumXOR(vector<int>& nums) {
    int n = nums.size();
    int x = 0;
    for (int i = 1; i < n; i++) {
      add(nums[i - 1]);
      x = max(x, check(nums[i]));
    }
    return x;
  }
};
/* 
贪心+位运算

 */
int findMaximumXOR(vector<int>& nums) {
  int n = nums.size();
  int mx = *max_element(nums.begin(), nums.end());
  int high_bit = mx ? 31 - __builtin_clz(mx) : -1;
  int ans = 0, mask = 0;
  unordered_set<int> seen;
  for (int i = high_bit; i >= 0; i--) {
    seen.clear();
    mask |= 1 << i;
    int new_ans = ans | (1 << i);  // 假设该位置是 1
    for (int x : nums) {
      x &= mask;
      if (seen.contains(new_ans ^ x)) {
        ans = new_ans;
        break;
      }
      seen.insert(x);
    }
  }
  return ans;
}
int main() {

  Solution test;
  return 0;
}