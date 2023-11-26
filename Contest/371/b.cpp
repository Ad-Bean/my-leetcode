#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        sort(access_times.begin(), access_times.end(), [&](auto a, auto b) {
            if (a[1] != b[1]) {
                return a[1] < b[1];
            } else {
                return a[0] < b[0];
            }
        });
        unordered_map<string, vector<int>> mp;
        unordered_map<string, bool> vis;
        vector<string> ans;
        for(const auto & access: access_times) {
            string name = access[0];
            string time = access[1];
            int timestamp = ((time[0] - '0') * 10 + (time[1] - '0')) * 60 + ((time[2] - '0') * 10 + (time[3] - '0'));
            mp[name].push_back(timestamp);
            if (mp[name].size() >= 3) {
                int len = mp[name].size();
                if (mp[name][len - 1] - mp[name][len - 3] < 60) {
                    if (!vis[name]) {
                        vis[name] = true;
                        ans.emplace_back(name);
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<string>> access_times {
        {"qzgyyji","1945"},
        {"qzgyyji","1855"},
        {"jsxkxtugi","1841"},
        {"jsxkxtugi","1859"},
        {"jsxkxtugi","1941"},
        {"hhjuaxal","1940"},
        {"hhjuaxal","1831"},
        {"hhjuaxal","1918"},
        {"hhjuaxal","1852"},
    };
    Solution test;
    vector<string> ans = test.findHighAccessEmployees(access_times);
    for (auto& access : ans) {
        cout << access << endl;
    }
    return 0;
}