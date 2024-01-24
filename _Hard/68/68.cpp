/*
 * [68] 文本左右对齐
 * https://leetcode.cn/problems/text-justification/description/
 *
 * 给定一个单词数组 words 和一个长度 maxWidth ，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
 * 
 * 你应该使用 “贪心算法” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth
 * 个字符。
 * 
 * 要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
 * 
 * 文本的最后一行应为左对齐，且单词之间不插入额外的空格。
 * 
 * 注意:
 * 
 * 
 * 单词是指由非空格字符组成的字符序列。
 * 每个单词的长度大于 0，小于等于 maxWidth。
 * 输入单词数组 words 至少包含一个单词。
 * 
 * 输入: words = ["This", "is", "an", "example", "of", "text", "justification."],
 * maxWidth = 16
 * 输出:
 * [
 * "This    is    an",
 * "example  of text", // 3 / 2 = 1 平均一个空格，左侧多 3 % 2 = 1
 * "justification.  "
 * ]
 * 
 * 
 * 输入:words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
 * 输出:
 * [
 * "What   must   be",
 * "acknowledgment  ",
 * "shall be        "
 * ]
 * 解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
 * 因为最后一行应为左对齐，而不是左右两端对齐。       
 * ⁠    第二行同样为左对齐，这是因为这行只包含一个单词。
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= words.length <= 300
 * 1 <= words[i].length <= 20
 * words[i] 由小写英文字母和符号组成
 * 1 <= maxWidth <= 100
 * words[i].length <= maxWidth
 * 
 * 
 * 方法一：贪心 + 双指针
 * 
 * 初始化右指针 r
 * 对于每一行，左指针 l，右指针 r 一直递增，记录当前字符串长度
 * 直到 words[l:r].size() + r - l 表示单词所有长度和间隔 1 个空格 的长度超过 maxWidth
 * 
 * 如果这是最后一行，左对齐，单词间一空格
 * 如果不是最后一行，左对齐，只有一个单词
 * 如果不是最后一行，填空格，不只一个单词
 * 
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
// @lc code=start
class Solution {

  // join(words[l:r], " ")
  string join(vector<string>& words, int l, int r, string sep) {
    string ret = words[l];
    for (int i = l + 1; i < r; i++) {
      ret += sep + words[i];
    }
    return ret;
  }

 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ans;
    int n = words.size();
    int r = 0;
    while (true) {
      int curlen = 0;
      int l = r;
      // r-l blanks
      while (r < n && curlen + words[r].size() + r - l <= maxWidth) {
        curlen += words[r++].size();
      }

      // last row
      if (r == n) {
        ans.emplace_back(join(words, l, r, " ") + string(maxWidth - s.size(), ' '));
        return ans;
      }

      // # of words
      int cnt = r - l;
      // remain spaces of all blanks
      int spaces = maxWidth - curlen;
      // only one word, left align
      if (cnt == 1) {
        ans.emplace_back(words[l] + string(spaces, ' '));
      } else {
        int avg = spaces / (cnt - 1);  // space width
        int ext = spaces % (cnt - 1);  // final space width
        // words[l]+blank1 +
        string sl = join(words, l, l + ext + 1, string(avg + 1, ' '));
        string sr = join(words, l + ext + 1, r, string(avg, ' '));
        ans.emplace_back(sl + string(avg, ' ') + sr);
      }
    }
    return ans;
  }
};
// @lc code=end
