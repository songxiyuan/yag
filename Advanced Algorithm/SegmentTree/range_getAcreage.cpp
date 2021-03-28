// https://blog.csdn.net/riba2534/article/details/76851233

/*

2 
10 10 30 30 
20 20 40 40 
0 

 */


#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 220
#define ll long long
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
struct Seg
{
    double l,r,h;//用来记录线段，左端点右端点和高度
    int f;//标记1-1
    Seg() {}
    Seg(double a,double b,double c,int d):l(a),r(b),h(c),f(d) {}
    bool operator < (const Seg &cmp) const
    {
        return h<cmp.h;
    }
} e[N];
struct node
{
    int cnt;
    double len;
} t[N<<2];//线段树的储存数组
double X[N];
void pushdown(int l,int r,int rt)
{
    if(t[rt].cnt)//当前的边被标记，就把当前的长度加上
        t[rt].len=X[r+1]-X[l];
    else if(l==r)//当为一个点的时候长度为0
        t[rt].len=0;
    else//其他情况把左右两个区间的值加上
        t[rt].len=t[rt<<1].len+t[rt<<1|1].len;
}
void update(int L,int R,int l,int r,int rt,int val)
{
    if(L<=l&&r<=R)
    {
        t[rt].cnt+=val;//加上标记的值
        pushdown(l,r,rt);//向下更新节点
        return;
    }
    int m=(l+r)>>1;
    if(L<=m) update(L,R,lson,val);
    if(R>m) update(L,R,rson,val);
    pushdown(l,r,rt);
}
int main()
{
    int n,q=1;
    double a,b,c,d;
    while(~scanf("%d",&n)&&n)
    {
        mem(t,0);
        int num=0;
        for(int i=0; i<n; i++)
        {
            scanf("%lf%lf%lf%lf",&a,&b,&c,&d);//x1，y1,x2,y2
            X[num]=a;
            e[num++]=Seg(a,c,b,1);//矩形下面用1来标记吗 x1,x2,y1
            X[num]=c;
            e[num++]=Seg(a,c,d,-1);//上面用-1来标记,x1,x2,y2
        }
        sort(X,X+num);//用于离散化
        sort(e,e+num);//把矩形的边的纵坐标从小到大排序
        int m=unique(X,X+num)-X;
        double ans=0;
        //从下往上扫描，
        for(int i=0; i<num; i++)
        {
            int l=lower_bound(X,X+m,e[i].l)-X;//找出离散化以后的值，在x记录中，找到第一个大于等于边e的左端点的x值，减去x
            int r=lower_bound(X,X+m,e[i].r)-X-1;//在x记录中，找到第一个大于等于边e的右端点的x值，减去x
            update(l,r,0,m,1,e[i].f);//左端点，右端点，0，第几个，标记1，数组1还是-1
            ans+=t[1].len*(e[i+1].h-e[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n",q++,ans);
    }
    return 0;
}