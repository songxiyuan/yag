/*
 * @lc app=leetcode id=1138 lang=cpp
 *
 * [1138] Alphabet Board Path
 */
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string alphabetBoardPath(string target) {
        int x=0;
        int y=0;
        string r="";
        for(int i=0;i<target.size();i++)
        {
            int newxy=target[i]-'a';
            int newx=newxy/5;
            int newy=newxy%5;
            if(newx-x>0)
            {
                while(x!=newx){r+="D";x++;};
            }
            else
            {
                while(x!=newx){r+="U";x--;};
            }
            if(newy-y>0)
            {
                while(y!=newy){r+="R";y++;};
            }
            else
            {
                while(y!=newy){r+="L";y--;};
            }
            r+="!";
        }
        return r;
    }
};


int main()
{
    Solution s;
    cout<<s.alphabetBoardPath("leet")<<endl;
    return 0;
}

