/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */
#include<vector>
#include<map>
using namespace std;


class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {
        //check every row
        //check every line
        //check every square
        for(int r=0;r<board.size();r++)
        {
            vector<int> ht(10,0);
            for(int l=0;l<board[r].size();l++)
            {
                if(board[r][l]=='.')continue;
                if(ht[board[r][l]-'0']==1)return false;
                ht[board[r][l]-'0']=1;
            }
        }
        
        for(int l=0;l<board[0].size();l++)
        {
            vector<int> ht(10,0);
            for(int r=0;r<board.size();r++)
            {
                if(board[r][l]=='.')continue;
                if(ht[board[r][l]-'0']==1)return false;
                ht[board[r][l]-'0']=1;
            }
        }
        
        if(board.size()%3!=0||board[0].size()%3!=0)return false;
        
        for(int r=0;r<board.size()-3;r+=3)
        {
            for(int l=0;l<board[r].size()-3;l+=3)
            {
                vector<int> ht(10,0);
                for(int i=r;i<r+3;i++)
                {
                    for(int j=l;j<l+3;j++)
                    {
                        if(board[i][j]=='.')continue;
                        if(ht[board[i][j]-'0']==1)return false;
                        ht[board[i][j]-'0']=1;
                    }
                }
            }
        }
        return true;
    }
};



int main()
{
    Solution s;
    vector<vector<char>> v=
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    
    s.isValidSudoku(v);
    return 0;
}


