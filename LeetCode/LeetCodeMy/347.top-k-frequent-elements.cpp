/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

#include<vector>
#include<unordered_map>
#include<queue>
#include<map>
#include<iostream>

using namespace std;

// Author: Huahuas
// Running time: 16 ms
class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;        
    for (const int num : nums)
      ++count[num];
    priority_queue<pair<int, int>> q;
    for (const auto& pair : count) {
      q.emplace(-pair.second, pair.first);
      if (q.size() > k) q.pop();
    }
    vector<int> ans;
    for (int i = 0; i < k; ++i) {
      ans.push_back(q.top().second);
      q.pop();
    }
    return ans;
  }

  vector<int> topKFrequent2(vector<int>& nums, int k) {//用桶排序
        unordered_map<int, int> count;
        int max_freq = 1;
        for (const int num : nums)
            max_freq = max(max_freq, ++count[num]);
        map<int, vector<int>> buckets;
        for (const auto& kv : count)
            buckets[kv.second].push_back(kv.first);
        vector<int> ans;
        for (int i = max_freq; i >= 1; --i) {
            auto it = buckets.find(i);
            if (it == buckets.end()) continue;
            ans.insert(ans.end(), it->second.begin(), it->second.end());
            if (ans.size() == k) return ans;
        }
        return ans;
    }
};

int main()
{
    int i;
    cout<<i;
    Solution s;
    vector<int> test={1,1,1,2,2,3};
    s.topKFrequent(test,2);

    return 0;
}
