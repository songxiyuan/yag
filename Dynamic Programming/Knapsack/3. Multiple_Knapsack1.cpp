/* 
有 N 件物品和一个容量为 V 的背包。放入第 i 件物品耗费的费用是 Ci1，得到的
价值是 Wi。求解将哪些物品装入背包可使价值总和最大。 

个数 背包大小
物品费用，耗费体积
价值
5 10
3 6 5 2 8
5 15 9 2 16
*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 1000000
using namespace std;
 
int dp[MAX];//存储最后背包最大能存多少
int value[MAX],weight[MAX],number[MAX];//分别存的是物品的价值，每一个的重量以及数量
int bag;
 
void ZeroOnePack(int weight,int value )//01背包
{
    int i;
    for(i = bag; i>=weight; i--)
    {
        dp[i] = max(dp[i],dp[i-weight]+value);
    }
}
void CompletePack(int weight,int value)//完全背包
{
    int i;
    for(i = weight; i<=bag; i++)
    {
        dp[i] = max(dp[i],dp[i-weight]+value);
    }
}
 
void MultiplePack(int weight,int value,int number)//多重背包
{
    if(bag<=number*weight)//如果总容量比这个物品的容量要小，那么这个物品可以直到取完，相当于完全背包
    {
        CompletePack(weight,value);
        return ;
    }
    else//否则就将多重背包转化为01背包
    {
        int k = 1;
        while(k<=number)
        {
            ZeroOnePack(k*weight,k*value);
            number = number-k;
            k = 2*k;//这里采用二进制思想
        }
        ZeroOnePack(number*weight,number*value);
    }
}
int main()
{
    int n;
    while(~scanf("%d%d",&bag,&n))
    {
        int i,sum=0;
        for(i = 0; i<n; i++)
        {
            scanf("%d",&number[i]);//输入数量
            scanf("%d",&value[i]);//输入价值  此题没有物品的重量，可以理解为体积和价值相等
        }
        memset(dp,0,sizeof(dp));
        for(i = 0; i<n; i++)
        {
            MultiplePack(value[i],value[i],number[i]);//调用多重背包,注意穿参的时候分别是重量，价值和数量
        }
        cout<<dp[bag]<<endl;
    }
    return 0;
}
