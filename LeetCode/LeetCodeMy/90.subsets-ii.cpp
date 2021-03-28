/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II

 */

#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> item;
        set<vector<int>> res_set;
        sort(nums.begin(),nums.end());
        result.push_back(item);
        dfs(0,nums,result,item,res_set);
        return result;
    }

    void dfs(int i,vector<int>& nums,vector<vector<int>> &result,vector<int> &item,set<vector<int>> &res_set)
    {
        if(i>=nums.size())
        {
            return;
        }
        item.push_back(nums[i]);
        if(res_set.find(item)==res_set.end())
        {
            result.push_back(item);
            res_set.insert(item);
        }
        dfs(i+1,nums,result,item,res_set);
        item.pop_back();
        dfs(i+1,nums,result,item,res_set);
    }
};

