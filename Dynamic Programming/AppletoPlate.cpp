// 把 M 个同样的苹果放在 N 个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？
// 注意：5、1、1 和 1、5、1 是同一种分法，即顺序无关。
#include <iostream>
using namespace std;

// 方法一：递归
int s(int m ,int n)
{
    if(m==0||n==1){
        return 1;
    }
    if(m<n)
    {
        return s(m,m);
    }
    if(m>=n) {
        return s(m, n - 1) + s(m - n, n);
    }
    return 0;
}

int** getdp(int m,int n)
{
     if( m == 0 || m == 1 || n == 1 )
    {
        return NULL;
    }
    // 动态数组！！！！
    int **dp=new int *[m+1];
    for(int i=0;i<=m;i++)
    {
        dp[i]=new int[n+1];
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=1;
        }
    }

    for(int i=2;i<=m;++i)
    {
        for(int j=2;j<=n;++j)
        {
            if(j>i)
            {
                dp[i][j]=dp[i][i];
            }
            else
            {
                dp[i][j]=dp[i-j][j]+dp[i][j-1];
            }
        }
    }
    return dp;
}

// 方法2：动态数组大小，然后递推
int s2(int m ,int n)
{
    if(m==0||n==1){
        return 1;
    }
    int **dp=getdp(m,n);
    return dp[m][n];
}
int main() {
    int m,n;
    while(cin>>m>>n)
    {
        cout<<s2(m,n)<<endl;
    }
    return 0;
}

