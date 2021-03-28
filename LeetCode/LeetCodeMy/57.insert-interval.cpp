/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.empty()) return vector<vector<int>>{};
        map<int,int>m;
        // sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[0] < b[0];});

        for(int i=0;i<intervals.size();i++)
        {
            auto it=m.find(intervals[i][0]);
            if(it==m.end()||it->second<intervals[i][1])
            {
                m[intervals[i][0]]=intervals[i][1];
            }
        }

        for(auto it=m.begin();it!=m.end();++it)
        {
            if()
        }
        
        m[intervals[0][0]]=intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (m.rbegin()->second < intervals[i][0]) m[intervals[i][0]]=intervals[i][1];
            else
                m.rbegin()->second = max((m.rbegin()->second), intervals[i][1]);
        }
        
        vector<vector<int>> res;
        for(auto it=m.begin();it!=m.end();++it)
        {
            vector<int> temp={it->first,it->second};
            res.push_back(temp);
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> test={{1,3},{2,6},{8,10},{15,18}};
    vector<int> t;
    Solution s;
    s.insert(test,t);
    return 0;
}

