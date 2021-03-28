#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

/*
主要是取一个区间,这个区间和为1,区间和用前缀和处理,对于区间[j,s], s[i]-s[j]=1, i是当前扫描的位数
求得最小j即可, 所以s[j]=s[i]-1, 用哈希表idx记录最开始s[j]所在位置idx[j]=idx[s[i]-1]
*/
class Solution {
public:
  int longestWPI(vector<int>& hours) {
    const int n = hours.size();
    for (int& v : hours) v = v > 8 ? 1 : -1;
    int s = 0;
    unordered_map<int, int> idx;    
    int ans = 0;
    for (int i = 0; i < hours.size(); ++i) {
      s += hours[i];
      if (s > 0) 
        ans = i + 1;
      if (!idx.count(s)) //如果当前idx里面没有s,
        idx[s] = i;
      if (idx.count(s - 1))
        ans = max(ans, i - idx[s - 1]);
    }
    return ans;
  }
}
  