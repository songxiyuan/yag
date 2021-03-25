#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int k;
    cin>>k;
    string str;
    cin>>str;
    int res=0;
    vector<vector<int> > dp(str.size(),vector<int>(str.size(),0));
    for(int i=0;i<str.size();i++)
    {
        for(int j=i;j<str.size();j++)
        {
            if(str[j]=='1')dp[i][j]++;
        }
    }

    cout<<res<<endl;
    return 0;
}


/*

2 4
ABCD
ABCE
1 2 3 4

 */


int knape(vector<int> &cost,vector<int> &worth,int maxV)//maxV最大容量
{
    vector<int> dp(cost.size(),0);
    for(int i=1;i<=cost.size();i++)
    {
        for(int v=maxV;v>cost[i];v--)
        {
            dp[v]=max(dp[v],dp[v-cost[i]]+worth[i]);
        }
    }
    return dp[cost.size()-1];
}