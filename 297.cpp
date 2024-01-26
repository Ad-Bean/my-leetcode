/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 *
 * https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/description/
 *
 * 
 * 序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
 * 
 * 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 /
 * 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
 * 
 * 提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode
 * 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
 * 
 * 
 * 
 * 输入：root = [1,2,3,null,null,4,5]
 * 输出：[1,2,3,null,null,4,5]
 * 
 * 
 * 输入：root = []
 * 输出：[]
 * 
 * 输入：root = [1]
 * 输出：[1]
 * 
 * 
 * 输入：root = [1,2]
 * 输出：[1,2]
 * 
 * 
 * 
 * 树中结点数在范围 [0, 10^4] 内
 * -1000 <= Node.val <= 1000
 * 
 * 
 * 方法一：BFS
 * 方法二：DFS
 * 带上空结点信息的是可逆的，所以仅有先序/后序/中序/层序都可以还原
 * 
 *  
 */

//  Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
// @lc code=start
class Codec {
  void dfs(TreeNode* node, string& str) {
    if (!node) {
      str += "None,";
    } else {
      str += to_string(node->val) + ",";
      dfs(node->left, str);
      dfs(node->right, str);
    }
  }

  TreeNode* getTree(list<string>& arr) {
    if (arr.front() == "None") {
      arr.erase(arr.begin());
      return nullptr;
    }

    TreeNode* root = new TreeNode(stoi(arr.front()));
    arr.erase(arr.begin());
    root->left = getTree(arr);
    root->right = getTree(arr);
    return root;
  }

 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string str;
    dfs(root, str);
    return str;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    list<string> arr;
    string str;
    for (const auto& ch : data) {
      if (ch == ',') {
        arr.emplace_back(str);
        str = "";
      } else {
        str += ch;
      }
    }
    if (!str.empty()) {
      arr.emplace_back(str);
      str = "";
    }
    return getTree(arr);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
