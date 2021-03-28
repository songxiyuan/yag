/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */
#include<string>
using namespace std;
class Solution {
public:
    bool isNumber(string s) {
        //先去掉前后空格
        //除了 e + - 数字 . 其他全部false
        //e在最前面和最后面都出错
        //符号只能出现在最前面或者e的后面
        //. 不能出现在最前面最后面以及e后面
        int first=s.find_first_not_of(" ");
        int last=s.find_last_not_of(" ");
        if(first==string::npos)return false;
        s=s.substr(first,last-first+1);
        bool exitsE=false;
        bool exitsPoint=false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='+'||s[i]=='-')
            {
                if(i!=0 || (i>0 && s[i-1]!='e'))
                {
                    return false;
                }
            }
            else if(s[i]=='e')
            {
                if(exitsE || i==0 || i==s.size()-1)return false;
                exitsE=true;
            }
            else if(s[i]=='.')
            {
                if(exitsPoint || exitsPoint || i==0 || i==s.size()-1)return false;
                exitsPoint=true;
            }
            else if(s[i]>='0' && s[i]<='9')
            {
                continue;
            }
            else return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    s.isNumber(" ");
    return 0;
}

