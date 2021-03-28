/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */
#include<vector>
using namespace std;
class Solution {
public:
    
    int firstMissingPositive(vector<int>& nums) {
        vector<int> count(8,0);
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<8;j++)
            {
                int temp=(1<<j);
                int test=temp&nums[i];
                if(nums[i]>0)count[j]+=((temp&nums[i])>0?1:0);
            }
        }
        int r=0;
        for(int i=0;i<count.size()-1;i++)
        {
            if(count[i]<count[i+1])
            {
                i|=(1<<(8-i));
            }
        }
        if(r==0)
        {
            for(int i=1;i<count.size();i++)
            {
                if(count[i]<count[i-1])
                {
                    r|=(1<<(i));
                    break;
                }
            }
        }
        
        return r;
    }
};

int main()
{
    Solution s;
    vector<int> nums={3,4,-1,1};
    s.firstMissingPositive(nums);
    return 0;
}

