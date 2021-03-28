/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
           reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string r="";
        int carry=0;
        int maxsize=a.size()>b.size()?a.size():b.size();
        for(int i=0;i<maxsize;i++)
        {
            r+="0";
           if(i<a.size())carry+=a[i]-'0';
            if(i<b.size())carry+=b[i]-'0';
            r[i]=carry%2+'0';
            carry/=2;
        }
        if(carry>0)r+=carry+'0';
        reverse(r.begin(),r.end());
        return r;
    }
};


int main()
{
    Solution s;
    s.addBinary("11","1");
    return 0;
}
