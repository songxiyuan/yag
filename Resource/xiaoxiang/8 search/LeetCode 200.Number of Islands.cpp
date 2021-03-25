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
    int numsIsland(vector<vector<char>>& grid)
    {
        int island_num=0;
        vector<vector<int>> mark(grid.size(), std::vector<int>(grid.size(), 0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(mark[i][j]==0&&grid[i][j]=='1')
                {
                    DFS(mark,grid,i,j);
                    island_num++;
                }
            }
        }
        return island_num;
    }
    void DFS(vector<vector<int>> &mark,vector<vector<char>> &grid,int x,int y)
    {
        mark[x][y]=1;
        static const int dx[]={-1,1,0,0};
        static const int dy[]={0,0,-1,1};
        for(int i=0;i<4;i++)
        {
            int newx=dx[i]+x;
            int newy=dy[i]+y;
            if(newx<0||newx>=mark.size()||newy<0||newy>=mark[newx].size())
                continue;
            if(mark[newx][newy]==0 && grid[newx][newy]=='1')
            {
                DFS(mark,grid,newx,newy);
            }
        }
    }
};

int main()
{
    vector<vector<char>> grid;
    char str[10][10] = {"11100","11000","00100","00011"};
    for(int i=0;i<4;i++)
    {
        grid.push_back(vector<char>());
        for(int j=0;j<5;j++)
        {
            grid[i].push_back(str[i][j]);
        }
    }
    Solution solve;
    printf("%d\n",solve.numsIsland(grid));
    system("PAUSE");
    return 0;
}