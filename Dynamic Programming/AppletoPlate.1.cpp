#include <iostream>
using namespace std;
 
int m,n;
 
int num[101][101];
 
int dp(int m, int n);
 
int main()
{
	cin>>m>>n;
	cout<<dp(m, n)<<endl;
    cin>>m>>n;
	return 0;
}
//  方法3：备忘录法
int dp(int m, int n)
{
	if(num[m][n]>0)	//如果备忘录中已经有记录，直接返回
	{
		return num[m][n];
	}
	else if(n==1||m==0||m==1)	//如果还剩1个饺子、或只有0个盘子、或只有1个盘子
	{
		num[m][n]=1;			//此时都只有1种装法
		return num[m][n];
	}
	else if(n>m)	//如果盘子数目比饺子数多
	{
		num[m][n]=dp(m, m);	//那么多余的盘子其实怎么用都用不上的，跟去掉多余盘子的情况一样
		return num[m][n];
	}
	else	//重点！我们把每一种情况分为两种子情况
	{
		num[m][n-1]=dp(m, n-1);		//第一种子情况，有一个空盘子
		num[m-n][n]=dp(m-n, n);		//第二种子情况，没有空盘子，也就是每个盘子里都至少一个饺子
		num[m][n]=num[m][n-1]+num[m-n][n];	//这两种子情况的装法数加起来=当前情况的装法数
		return num[m][n];
	}
}
