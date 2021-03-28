/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int r=1;
        int pre=nums[0];
        vector<int>::iterator it;
        for(it=nums.begin()+1;it!=nums.end();)
        {
            if(*it!=pre)
            {
                pre=*it;
                r++;
                it++;
            }
            else
            {
                it=nums.erase(it);
            }
        }
        return r;
    }
};

int main()
{
    Solution s;
    vector<int> nums={1,1};
    s.removeDuplicates(nums);
    return 0;
}

