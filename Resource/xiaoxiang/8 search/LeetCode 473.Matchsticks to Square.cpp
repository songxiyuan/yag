#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution
{
    public:
    bool makesquare(vector<int>& nums)
    {
        if(nums.size()<4)
        {
            return false;
        }
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        if(sum%4) 
            return false;
        sort(nums.rbegin(),nums.rend());//从大到小排序
        int bucket[4]={0};
        return dfs(0,nums,sum/4,bucket);
    }
    bool dfs(int i,vector<int>& nums,int target,int bucket[])
    {
        if(i>=nums.size())
        {
            return bucket[0]==target && bucket[1]==target && bucket[2]==target && bucket[3]==target;
        }
        for(int j=0;j<4;j++)
        {
            if(bucket[j]+nums[i]>target)
            {
                continue;
            }
            bucket[j]+=nums[i];
            if(dfs(i+1,nums,target,bucket))
                return true;
            bucket[j]-=nums[i];
        }
        return false;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(3);
    Solution solve;
    printf("%d\n",solve.makesquare(nums));
    system("PAUSE"); 
    return 0;
}
