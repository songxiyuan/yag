/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

#include<string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        //brute force way
        
        if(s.size()==0)
        {
            if(p.size()==0)return true;
            else return false;
        }
        
        for(int i=0;i<p.size();i++)
        {
            if(p[0]=='?')
            {
                return isMatch(s.substr(1),p.substr(1));
            }
            else if(p[0]=='*')
            {
                for(int j=0;j<=s.size();j++)
                {
                    if(isMatch(s.substr(j),p.substr(1)))return true;
                }
                return false;
            }
            else
            {
                if(p[0]==s[0])
                    return isMatch(s.substr(1),p.substr(1));
                else
                    return  false;
            }
        }
        return false;//s还有值，但是p没有值了
    }
};

int main()
{
    Solution s;
    s.isMatch("aa","*");
    return 0;
}

