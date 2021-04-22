//迪杰斯特拉算法 C++实现

#include<stdio.h>
#include<stdlib.h>
#define max1 10000000  //原词条这里的值太大，导致溢出，后面比较大小时会出错
int a[1000][1000];
int d[1000];//d表示源节点到该节点的最小距离
int p[1000];//p标记访问过的节点
int i, j, k;
int m;//m代表边数
int n;//n代表点数
int main()
{
    scanf("%d%d",&n,&m);
    int    min1;
    int    x,y,z;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        a[x][y]=z;
        a[y][x]=z;
    }
    for( i=1; i<=n; i++)
        d[i]=max1;
    d[1]=0;
    for(i=1;i<=n;i++)
    {
        min1 = max1;
        //下面这个for循环的功能类似冒泡排序，目的是找到未访问节点中d[j]值最小的那个节点，
        //作为下一个访问节点，用k标记
        for(j=1;j<=n;j++)
            if(!p[j]&&d[j]<min1)
            {
                min1=d[j];
                k=j;
            }
        //p[k]=d[k]; // 这是原来的代码，用下一 条代码替代。初始时，执行到这里k=1，而d[1]=0
       //从而p[1]等于0，这样的话，上面的循环在之后的每次执行之后，k还是等于1。
        p[k] = 1; //置1表示第k个节点已经访问过了
        for(j=1;j<=n;j++)
            if(a[k][j]!=0&&!p[j]&&d[j]>d[k]+a[k][j])
                d[j]=d[k]+a[k][j];
    }
    //最终输出从源节点到其他每个节点的最小距离
    for(i=1;i<n;i++)
        printf("%d->",d[i]);
    printf("%d\n",d[n]); 
    return 0;
}


// 弗洛伊德算法
/*



#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define max 1000000000
 
int d[1000][1000],path[1000][1000];
int main1()
{
    int i,j,k,m,n;
    int x,y,z;
    scanf("%d%d",&n,&m);
     
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            d[i][j]=max;
            path[i][j]=j;
    }
     
    for(i=1;i<=m;i++) {
            scanf("%d%d%d",&x,&y,&z);
            d[x][y]=z;
            d[y][x]=z;
    }
     
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++) {
                if(d[i][k]+d[k][j]<d[i][j]) {
                    d[i][j]=d[i][k]+d[k][j];
                    path[i][j]=path[i][k];
                }
            }
    for(i=1;i<=n;i++)
        for(j=1;j<=i;j++)
          if (i!=j) printf("%d->%d:%d\n",i,j,d[i][j]);
    int f, en;
    scanf("%d%d",&f,&en);
    while (f!=en) {
        printf("%d->",f);
        f=path[f][en];
    }
    printf("%d\n",en);
    return 0;
}



 */




#include<iostream>
#include<vector>
using namespace std;
const int &INF=100000000;
void floyd(vector<vector<int> > &distmap,//可被更新的邻接矩阵，更新后不能确定原有边
           vector<vector<int> > &path)//路径上到达该点的中转点
//福利：这个函数没有用除INF外的任何全局量，可以直接复制！
{
    const int &NODE=distmap.size();//用邻接矩阵的大小传递顶点个数，减少参数传递
    path.assign(NODE,vector<int>(NODE,-1));//初始化路径数组 
    for(int k=1; k!=NODE; ++k)//对于每一个中转点
        for(int i=0; i!=NODE; ++i)//枚举源点
            for(int j=0; j!=NODE; ++j)//枚举终点
                if(distmap[i][j]>distmap[i][k]+distmap[k][j])//不满足三角不等式
                {
                    distmap[i][j]=distmap[i][k]+distmap[k][j];//更新
                    path[i][j]=k;//记录路径
                }
}
void print(const int &beg,const int &end,
           const vector<vector<int> > &path)//传引用，避免拷贝，不占用内存空间
           //也可以用栈结构先进后出的特性来代替函数递归 
{
    if(path[beg][end]>=0)
    {
        print(beg,path[beg][end],path);
        print(path[beg][end],end,path);
    }
    else cout<<"->"<<end;
}
int main2()
{
    int n_num,e_num,beg,end;//含义见下
    cout<<"（不处理负权回路）输入点数、边数：";
    cin>>n_num>>e_num;
    vector<vector<int> > path,
          distmap(n_num,vector<int>(n_num,INF));//默认初始化邻接矩阵
    for(int i=0,p,q; i!=e_num; ++i)
    {
        cout<<"输入第"<<i+1<<"条边的起点、终点、长度（100000000代表无穷大，不联通）：";
        cin>>p>>q;
        cin>>distmap[p][q];
    }
    floyd(distmap,path);
    cout<<"计算完毕，可以开始查询，请输入出发点和终点：";
    cin>>beg>>end;
    cout<<"最短距离为"<<distmap[beg][end]<<"，打印路径："<<beg;
    print(beg,end,path);
}