//用弗洛伊德算法思想求最小环 https://blog.csdn.net/qq_34731703/article/details/54729244

#include<algorithm>
#include<iostream>
#include<cstdio>
 
using namespace std;
 
const int maxn = 105;
const int inf = INT_MAX;
 
class Floyd{
public:
 
    int n,m;
    int dis[maxn][maxn];//记录互相最近距离，原始都是最大值;
    int mp[maxn][maxn];// 记录原始输入的距离数据
 
    int init(){
        if(scanf("%d%d",&n,&m)!=2)return -1;
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)mp[i][j]=dis[i][j]=inf;
        for(int i=0;i<m;i++){
            int u,v,w;scanf("%d%d%d",&u,&v,&w);
            mp[u][v]=mp[v][u]=dis[u][v]=dis[v][u]=min(w,mp[u][v]);
        }
    }
 
    void floyd(){
        int MinCost = inf;
        for(int k=1;k<=n;k++){
            for(int i=1;i<k;i++)
                for(int j=i+1;j<k;j++)
                    MinCost = min(MinCost,dis[i][j]+mp[i][k]+mp[k][j]);//跟新k点之前枚举ij求经过ijk的最小环
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);      //跟新k点，记录最近距离
        }
        if(MinCost==inf)puts("It's impossible.");
        else printf("%d\n",MinCost);
    }
 
}fd;
 
int main()
{
    while(~fd.init())fd.floyd();
    return 0;
}
