/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */
#include<vector>
class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        if(nums.size()==0)return 0;
        std::vector<int> dp(nums.size(),0);
        dp[0]=1;
        int LIS=1;
        for(int i=1;i<dp.size();i++)
        {
            dp[i]=1;
            for(int j=i-1;j>0;j++)
            {
                if(nums[i]>nums[j] && dp[i]<dp[j]+1)
                    dp[i]=dp[j]+1;
            }
            if(LIS<dp[i])LIS=dp[i];
        }
        return LIS;
    }


    // 机智解法！！！
    // int lengthOfLIS(vector<int>& nums) {
    // vector<int> res;
    // for(int i=0; i<nums.size(); i++) {
    //     auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
    //     if(it==res.end()) res.push_back(nums[i]);
    //     else *it = nums[i];
    // }
    // return res.size();
    // }
};

