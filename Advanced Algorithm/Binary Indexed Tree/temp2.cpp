#include<iostream>
#include<cstring>
using namespace std;


// 区间修改，单点查询 询问i位置处的值和将[l,r]位置上所有值增加C https://www.bilibili.com/video/av36663299/?p=1
int a[50005];//原始数组
int c[50005];//储存的树状数组
int n,m;

inline int lowbit(int x)//
{
    return x&(-x);
}

void update(int i, int x)//i是第几个数，x是数值是多少
{
    while(i<=n)//当当前数小于最大值时
    {
        c[i]+=x;
        i+=lowbit(i);//更新父节点
    }
}

int sum(int i)
{
    int res=0;
    while(i>0)
    {
        res+=c[i];
        i-=lowbit(i);
    }
    return res;
}

int main()
{
    
    memset(a,0,sizeof(c));
    memset(c,0,sizeof(c));
    cin>>n>>m;//n个数，m次操作
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int d=a[i]-a[i-1];
        update(i,d);
    }
    for(int i=1;i<=m;i++)
    {
        int opt;
        cin>>opt;
        if(opt==1)//更新添加操作
        {
            int l,r,c;
            cin>>l>>r>>c;
            update(l,c);//l到r区间添加数组
            update(r+1,-c);
        }
        if(opt==2)//查询
        {
            int i;
            cin>>i;
            cout<<i<<":"<<sum(i)<<endl;
        }

    }
    return 0;
}

/*

10 3
1 2 3 4 5 6 7 8 9 10
2
3
1
2 3 1
2
3



Case 1:
6
33
59

 */