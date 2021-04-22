
#include <iostream>
#include <cstring>
using namespace std;

#define mod 100000000
int M,N,top = 0;
int cur[12][12];
int mark[12][12];
int r;
void dfs(int m,int n)
{
    if(m==M-1 && n==N)//最后一个数
    {
        r++;
        return;
    }
    else if(n==N)dfs(m+1,0);

    if(cur[m][n]==0)dfs(m,n+1);//空地不能选

    if(n==0)
    {
        if(m==0)//第一行第一个
        {
            dfs(0,1);
            mark[0][0]=1;
            dfs(0,1);
        }
        else if(mark[m-1][0]==0)
        {
            dfs(m,n+1);
            mark[m][0]==1;
            dfs(m,n+1);
        }
    }
    else
    {
        if(mark[m-1][n]==0 && mark[m][n-1]==0)
        {
            dfs(m,n+1);
            mark[m][n]==1;
            dfs(m,n+1);
        }
    }
}

int main()
{
    {
        r=0;
        cout<<"asdfads";
        cin>>M>>N;
        cout<<"asdfads";
        cin>>N;
        for(int i=0;i<M;++i)
        {
            for(int j=0;j<N;++j)
            {
                int num;
                cin>>num;
                cur[i][j]=num;
                mark[i][j]=0;
            }
        }
        dfs(0,0);
        cout<<"结果 "<<r<<endl;
    }
    return 0;
}