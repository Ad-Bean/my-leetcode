#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int pseudoPalindromicPaths(TreeNode* root) {
    vector<int> cnt(10);
    function<bool(void)> isPalindrome = [&]() {
        int odd = 0;
        for (const int& num : cnt) {
            if ((num & 1)) {
                odd++;
            }
        }
        return odd <= 1;
    };
    function<int(TreeNode*)> dfs = [&] (TreeNode* root) -> int {
        if (!root) return 0;
        cnt[root->val]++;
        int res = 0;
        if (root->left == nullptr && root->right == nullptr) {
            if(isPalindrome()) {
                res = 1;
            }
        } else {
            res = dfs(root->left) + dfs(root->right);
        }
        cnt[root->val]--;
        return res;
    };
    return dfs(root);
  }
};

int main() {

  Solution test;
  return 0;
}