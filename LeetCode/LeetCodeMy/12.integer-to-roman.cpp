/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string str="";
        while(num>0)
        {
            if(num/1000>0)
            {
                num/=1000;
                str+='M';
            }
            else if(num/900>0)
            {
                num/=900;
                str+="CM";
            }
            else if(num/500>0)
            {
                num/=500;
                str+="D";
            }
            else if(num/400>0)
            {
                num/=400;
                str+="CD";
            }
            else if(num/100>0)
            {
                num/=100;
                str+="C";
            }
            else if(num/90>0)
            {
                num/=90;
                str+="XC";
            }
            else if(num/50>0)
            {
                num/=50;
                str+="L";
            }
            else if(num/40>0)
            {
                num/=40;
                str+="XL";
            }
            else if(num/10>0)
            {
                num/=10;
                str+="X";
            }
            else if(num/9>0)
            {
                num/=9;
                str+="IX";
            }
            else if(num/5>0)
            {
                num/=5;
                str+="V";
            }
            else if(num/4>0)
            {
                num/=4;
                str+="IV";
            }
            else if(num-1>=0)
            {
                num-=1;
                str+="I";
                if(num==0)break;
            }
        }
        return str;
    }
};

int main()
{
    Solution s;
    cout<<s.intToRoman(3);
    return 0;
}

