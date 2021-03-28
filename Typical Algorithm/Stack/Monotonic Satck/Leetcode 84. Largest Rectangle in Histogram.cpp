#include<vector>
#include<stack>
#include<algorithm>
using namespace std;


int largestRectangleArea(vector<int> &height) 
{
    int ret = 0;
    height.push_back(0);
    vector<int> index;
    for(int i = 0; i < height.size(); i++) 
    {
        while(index.size() > 0 && height[index.back()] >= height[i]) 
        {
            int h = height[index.back()];
            index.pop_back();
            int sidx = index.size() > 0 ? index.back() : -1;
            ret = max(ret, h * (i-sidx-1));
        }
        index.push_back(i);
    }
    return ret;
}

int maximalRectangle(vector<vector<char>>& matrix) 
{
    if (matrix.empty())  return 0;
    vector<int> height(matrix[0].size(), 0);
    int maxRect= 0;
    for(int i = 0; i < matrix.size(); ++i) 
    {
        for(int j = 0; j < height.size(); ++j) 
        {
            if(matrix[i][j] == '0')    height[j] = 0;
            else    ++height[j];
        }
        maxRect = max(maxRect, largestRectangleArea(height));
        height.pop_back();
    }
    return maxRect;
}

