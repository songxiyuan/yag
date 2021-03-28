/*
 * @lc app=leetcode id=803 lang=cpp
 *
 * [803] Bricks Falling When Hit
 */

//并查集 反向检测
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
class UF{
    public:
        vector<int> sets;
        UF(int num) {
            sets = vector<int>(num, -1);
        }
        int Find(int child) {
            if (sets[child] < 0)    return child;
            return sets[child] = Find(sets[child]); 
        }
        void Union(int i, int j) {
            int root1 = Find(i);
            int root2 = Find(j);
            if (root1 == root2) return;
            int newSize = sets[root1] + sets[root2];
            // root1 is more negative (larger)
            if (sets[root1] < sets[root2]) {
                sets[root2] = root1;
                sets[root1] = newSize;
            } else {
                sets[root1] = root2;
                sets[root2] = newSize;
            }
            
        }
        int GetRootRank(int i) {
            return -sets[Find(i)];
        }
    };
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> mat = grid;
        for(auto &hit: hits)    mat[hit[0]][hit[1]] = 0;

        vector<int> res;
        UF myUf(m*n+1);
        // get the last step union find
        // let m*n node is the roof node
        for(int j=0; j<n; ++j){
            if(mat[0][j] == 1){
                myUf.Union(j, m*n);
            }
        }

        for(int i=1; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(mat[i][j] == 1){
                    if(mat[i-1][j] == 1){
                        myUf.Union(i*n+j, (i-1)*n+j);
                    }
                    if(j-1>=0 && mat[i][j-1]==1){
                        myUf.Union(i*n+j, i*n+(j-1));
                    }
                }
            }
        }

        // put brick back
        for(int k = hits.size()-1; k>=0; --k){
            int x = hits[k][0];
            int y = hits[k][1];

            if(grid[x][y] == 1){
                int prevRoofRank = myUf.GetRootRank(m*n);
                mat[x][y] = 1;
                if(x+1<m && mat[x+1][y] == 1){
                   myUf.Union((x+1)*n+y, x*n+y);
                }
                if(x-1>=0 && mat[x-1][y] == 1){
                    myUf.Union((x-1)*n+y, x*n+y);
                }
                if(y+1<n && mat[x][y+1] == 1){
                    myUf.Union(x*n+y+1, x*n+y);
                }
                if(y-1>=0 && mat[x][y-1] == 1){
                    myUf.Union(x*n+y-1, x*n+y);
                }
                if(x==0){ // merge to roof node
                    myUf.Union(m*n, x*n+y);
                }
                int curRoofRank = myUf.GetRootRank(m*n);
                res.push_back(max(curRoofRank- prevRoofRank -1, 0));
            }
            else{
                res.push_back(0);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    
    }
};