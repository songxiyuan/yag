#include<cstdio>
#include<cstring>
using namespace std;


// 单点修改区间查询
// 排兵布阵 https://www.jianshu.com/p/bed872d87a43

int c[50005];//储存的树状数组
int n;

inline int lowbit(int x)//
{
    return x&(-x);
}

void update(int i, int x)//i是第几个数，x是数值是多少
{
    while(i<=n)//当当前数小于最大值时
    {
        c[i]+=x;//
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
    int T, cnt;
    scanf("%d", &T);
    for(cnt=1; cnt<=T; cnt++)
    {
        int i, temp;
        char op[10];
        memset(c,0,sizeof(c));

        scanf("%d", &n);
        for(i=1 ;i<=n; i++)
        {
            scanf("%d", &temp);
            update(i, temp);
        }
        printf("Case %d:\n", cnt);
        while(~scanf("%s", op))
        {
            int l, r, k;
            if(!strcmp(op,"End")) break;
            if(!strcmp(op,"Query"))
            {
                scanf("%d%d", &l, &r);
                printf("%d\n", sum(r)-sum(l-1));
            }
            if(!strcmp(op,"Add"))
            {
                scanf("%d%d", &k, &temp);
                update(k, temp);
            }
            if(!strcmp(op,"Sub"))
            {
                scanf("%d%d", &k, &temp);
                update(k, -temp);
            }
        }
    }
    return 0;
}

/*

1
10
1 2 3 4 5 6 7 8 9 10
Query 1 3
Add 3 6
Query 2 7
Sub 10 2
Add 6 3
Query 3 10
End


Case 1:
6
33
59

 */