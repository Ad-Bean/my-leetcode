#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
/*
Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) on a 2D plane and walk on the path specified by path.

Return true if the path crosses itself at any point, that is, if at any time you are on a location you have previously visited. Return false otherwise.

Input: path = "NES"
Output: false 
Explanation: Notice that the path doesn't cross any point more than once.

方法一：哈希 + 模拟

n <= 1e4
所以坐标最长 +-10000, 0 或者 0,+-10000

哈希可以做 x * 20001 + y
*/


class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        unordered_map<int, bool> vis;
        vis[0] = true;
        for (const char& dir: path) {
            switch (dir) {
                case 'N': x--; break; 
                case 'S': x++; break; 
                case 'W': y--; break; 
                case 'E': y++; break; 
            }
            int p = x * 20001 + y;
            if (vis[p]) {
                return true;
            } else {
                vis[p] = true;
            }
        }
        return false;
        
    }
};
int main() {

Solution test;
return 0;
}