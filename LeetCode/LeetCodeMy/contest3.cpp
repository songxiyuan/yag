#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
class Solution0 {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m;
        for(int i=0;i<arr1.size();i++)
        {
            if(m.find(arr1[i])==m.end())
            {
                m[arr1[i]]=1;
            }
            else
            {
                m[arr1[i]]++;
            }
        }
        vector<int> res;
        for(int i=0;i<arr2.size();i++)
        {
            for(int j=0;j<m[arr2[i]];j++)res.push_back(arr2[i]);
            m.erase(arr2[i]);
        }
      
        map<int,int>::iterator it;
        for (it = m.begin(); it!=m.end(); it++)
        {
            for(int j=0;j<(*it).second;j++)res.push_back((*it).first);
        }
        return res;
    }
};

int main0()
{
    Solution0 s;
    vector<int> a1={2,3,1,3,2,4,6,7,9,2,19};
    vector<int> a2={2,1,4,3,9,6};
    s.relativeSortArray(a1, a2);
    return 0;
}

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        vector<int> dp(hours.size(),0);
        int max=0;
        int maxAll=0;
        int i=0;
        if(hours[0]>8)
        {
            dp[0]=1;
            max=1;
            maxAll=1;
            i++;
        }
        else
        {
             while(++i<hours.size() && hours[i]<=8);
        }
        
        for(i;i<hours.size();i++)
        {
            if(hours[i]==0)
            {
                if(dp[i-1]>0 && maxAll<max)maxAll=max;
                max=0;
                while(++i<hours.size()&&hours[i]<=8);
            }
            else if(hours[i]>8)
            {
                dp[i]=dp[i-1]+1;
                max++;
            }
            else
            {
                dp[i]=dp[i-1]-1;
                max++;
            }
        }
        if(dp[hours.size()-1]>0 && maxAll<max)maxAll=max;
        return maxAll;
    }
};
int main()
{
    Solution s;
    vector<int> v={6,9,6};
    s.longestWPI(v);
    return 0;
}