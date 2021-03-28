/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */

#include<string>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        if(s.length<2)return 0;
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        dp[0][0]=1;
        // for(int i=0)
        {

        }
    }
};

