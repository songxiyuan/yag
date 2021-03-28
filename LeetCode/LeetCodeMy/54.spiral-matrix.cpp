/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

#include<vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size()-1;
        int column=matrix[0].size();
        
        int direct=1;
        
        int x=0;
        int y=-1;
        
        vector<int> r;
        
        while((row>0&&column>=0)||(column>0 && row>=0))
        {
            if(direct==1)
            {
                int temp=column;
                while(temp-->0)
                {
                    r.push_back(matrix[x][++y]);
                }
                column--;
                direct=2;
            }
            else if(direct==2)
            {
                int temp=row;
                while(temp-->0)
                {
                    r.push_back(matrix[++x][y]);
                }
                row--;
                direct=3;
            }
            else if(direct==3)
            {
                int temp=column;
                while(temp-->0)
                {
                    r.push_back(matrix[x][--y]);
                }
                column--;
                direct=4;
            }
            else if(direct==4)
            {
                int temp=row;
                while(temp-->0)
                {
                    r.push_back(matrix[--x][y]);
                }
                row--;
                direct=1;
            }
        }
        return r;
    }
};


int main()
{
    vector<vector<int>> v=  {
                                { 1, 2, 3 }
                            };
    Solution s;
    s.spiralOrder(v);
    return 0;
}

