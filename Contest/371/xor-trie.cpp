#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int ch[400005 << 5][2], tot = 0, n, a[400005];
void insert(int x) {
  int p = 0;
  for (int i = 31; i >= 0; i--) {
    int c = (x >> i) & 1;
    if (!ch[p][c])
      ch[p][c] = ++tot;
    p = ch[p][c];
  }
}
int get(int x) {
  int p = 0, v = 0, ans = 0;
  for (int i = 31; i >= 0; i--) {
    int c = (x >> i) & 1;
    int o;
    if (c)
      o = 0;
    else
      o = 1;
    if (ch[v][o])
      v = ch[v][o], ans = (ans << 1) | 1;
    else
      v = ch[v][c], ans <<= 1;
    p = ch[p][c];
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  int ans = 0;
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]), insert(a[i]);
  for (int i = 1; i <= n; i++)
    ans = max(ans, get(a[i]));
  printf("%d\n", ans);
  return 0;
}