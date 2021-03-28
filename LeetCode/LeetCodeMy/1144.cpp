#include<vector>
using namespace std;
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        if(nums.size()<2)return 0;
        int r=1;
        int before=nums[0];
        bool up;
        bool start=true;
        for(int i=1;i<nums.size();i++)
        {
            if(start)
            {
                if(nums[i]-nums[i-1]>0)
                {
                    up=true;
                    before=nums[i];
                    r++;
                    start=false;
                }
                else if(nums[i]-nums[i-1]<0)
                {
                    up=false;
                    before=nums[i];
                    r++;
                    start=false;
                }
                
            }
            else
            {
                if(nums[i]-nums[i-1]>0)
                {
                    //本来就是下降，
                    if(!up)
                    {
                        r++;
                        up=true;
                    }
                    before=nums[i];
                    
                }
                else if(nums[i]-nums[i-1]<0)
                {
                    if(up)
                    {
                        r++;
                        up=false;
                    }
                    before=nums[i];
                }
            }

        }
        return r;
    }
};

int main()
{
    Solution s;
    vector<int> t={9,6,1,6,2};
    s.movesToMakeZigzag(t);
    return 0;
}