#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
/* 
请你设计并实现一个能够对其中的值进行跟踪的数据结构，并支持对频率相关查询进行应答。

实现 FrequencyTracker 类：

FrequencyTracker()：使用一个空数组初始化 FrequencyTracker 对象。
void add(int number)：添加一个 number 到数据结构中。
void deleteOne(int number)：从数据结构中删除一个 number 。数据结构 可能不包含 number ，在这种情况下不删除任何内容。
bool hasFrequency(int frequency): 如果数据结构中存在出现 frequency 次的数字，则返回 true，否则返回 false。

1 <= number <= 1e5

输入
["FrequencyTracker", "add", "add", "hasFrequency"]
[[], [3], [3], [2]]
输出
[null, null, null, true]

解释
FrequencyTracker frequencyTracker = new FrequencyTracker();
frequencyTracker.add(3); // 数据结构现在包含 [3]
frequencyTracker.add(3); // 数据结构现在包含 [3, 3]
frequencyTracker.hasFrequency(2); // 返回 true ，因为 3 出现 2 次

方法一：哈希表
首先记录每个数字出现的次数 unordered_map<int, int> num_freq;
由于 hasFrequency 最多调用 1e5 次，所以可以再加一个哈希表，记录频次是否存在

细节要注意，更新时：新频次加一，旧频次减一
 */
class FrequencyTracker {
  unordered_map<int, int> num_freq;
  unordered_map<int, int> freq_cnt;

 public:
  FrequencyTracker() {}

  void add(int number) {
    num_freq[number]++;
    freq_cnt[num_freq[number]]++;      // 新频次加一
    freq_cnt[num_freq[number] - 1]--;  // 旧频次减一
  }

  void deleteOne(int number) {
    // 删除一个
    if (num_freq[number]) {
      num_freq[number]--;                    // 频次减一
      if (freq_cnt[num_freq[number] + 1]) {  // 如果存在旧频次
        freq_cnt[num_freq[number] + 1]--;    // 旧频次减一
        if (num_freq[number]) {              // 如果新频次不为 0
          freq_cnt[num_freq[number]]++;      // 新频次加一
        }
      }
    }
  }

  bool hasFrequency(int frequency) { return freq_cnt[frequency] > 0; }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */

int main() {
  FrequencyTracker* frequencyTracker = new FrequencyTracker();
  frequencyTracker->add(5);
  frequencyTracker->add(5);
  cout << frequencyTracker->hasFrequency(1) << endl;
  cout << frequencyTracker->hasFrequency(2) << endl;
  frequencyTracker->add(6);
  frequencyTracker->add(5);
  frequencyTracker->add(1);
  return 0;
}
