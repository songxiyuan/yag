/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void dfs(vector<int> &candidates,int x,int target, vector<int> &local, vector<vector<int>> &result)
    {
        if(target==0)
        {
            result.push_back(local);
            return;
        }
        if(target<0 || x>=candidates.size())return;

        for(int i=x;i<candidates.size();i++)
        {
            if(i>0&&candidates[x]==candidates[x-1]&&local.size()==0)continue;
            local.push_back(candidates[x]);
            dfs(candidates,x+1,target-candidates[x],local,result);
            local.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> local;
        vector<vector<int>> result;
        dfs(candidates,0,target,local,result);
        return result;
    }
};
int main()
{
    Solution s;
    vector<int> c={10,1,2,7,6,1,5};
    s.combinationSum2(c,8);
    return 0;
}

