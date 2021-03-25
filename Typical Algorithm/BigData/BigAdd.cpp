#include <iostream>
#include <string>
using namespace std;

void bigAdd(string num1,string num2,string &res)
{
    int carry=0;
    int len1=num1.length()-1;
    int len2=num2.length()-1;
    res="";
    while(len1>=0||len2>=0)
    {
        int a=len1>=0? num1[len1--]-'0':0;
        int b=len2>=0? num2[len2--]-'0':0;
        int tmp=a+b+carry;
        carry=tmp/10;
        res=to_string(long(tmp%10))+res;
    }
    if(carry)
    {
        res=to_string(long(carry))+res;
    }
}

int main()
{
    string s;
    bigAdd("1111111111111111","1111111111",s);
    cout<<s<<endl;
    int a;
    cin>>a;
    return 0;
}