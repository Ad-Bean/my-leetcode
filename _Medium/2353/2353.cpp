
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
/* 
设计一个支持下述操作的食物评分系统：

修改 系统中列出的某种食物的评分。
返回系统中某一类烹饪方式下评分最高的食物。

方法一：哈希表 + 平衡树

unordered_map<string, pis> 食物 - 烹饪方式，评分
unordered_map<string, set<pis>> 烹饪方式 - 食物+评分

需要注意
String highestRated(String cuisine) 返回指定烹饪方式 cuisine 下评分最高的食物的名字。
如果存在并列，返回 字典序较小 的名字。

如果 set 按照 rating 从小到大排，此时 food 名字也从小到大，所以难以 O1 找到评分相同时，字典序较小的


-16 r -16 s 
但如果 set 按照 rating 从大到小排，此时 food 从小到大，直接返回第一个
 */
typedef pair<int, string> pis;
class FoodRatings {
  unordered_map<string, pis> food_cui_rating;
  unordered_map<string, set<pis>> cui_set;

 public:
  FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
    int n = foods.size();
    for (int i = 0; i < n; i++) {
      auto &f = foods[i], &c = cuisines[i];
      int r = ratings[i];
      food_cui_rating[f] = {r, c};
      cui_set[c].emplace(-r, f);
    }
  }

  void changeRating(string food, int newRating) {
    auto& [r, c] = food_cui_rating[food];
    auto& s = cui_set[c];
    s.erase({-r, food});
    s.emplace(-newRating, food);
    r = newRating;
  }

  string highestRated(string cuisine) { return cui_set[cuisine].begin()->second; }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
int main() {

  Solution test;
  return 0;
}