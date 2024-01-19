#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.

方法一：汉明距离
在信息论中，两个等长字符串之间的汉明距离（英语：Hamming distance）是两个字符串对应位置的不同字符的个数。
换句话说，它就是将一个字符串变换成另外一个字符串所需要替换的字符个数。

直接亦或后算 1 的位数

 */
class Solution {
 public:
  int hammingDistance(int x, int y) { return __builtin_popcount(x ^ y); }
};
int main() {

  Solution test;
  return 0;
}
