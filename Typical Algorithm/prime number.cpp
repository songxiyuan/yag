#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
bool isPrime_3( int num )
{
    //两个较小数另外处理
    if(num ==2|| num==3 )
        return 1 ;
    //不在6的倍数两侧的一定不是质数
    if(num %6!= 1&&num %6!= 5)
        return 0 ;
    int tmp =sqrt( num);
    //在6的倍数两侧的也可能不是质数
    for(int i= 5;i <=tmp; i+=6 )
        if(num %i== 0||num %(i+ 2)==0 )
            return 0 ;
    //排除所有，剩余的是质数
    return 1 ;
}

int main()
{
    int m;
    while(cin>>m)
    {
        if(m==1)cout<<0;
        else
        {
            int count=0;
            for(int i=2;i<=m;i++)
            {
                if(isPrime_3(i))count++;
            }
            cout<<count;
        }
    }
}
