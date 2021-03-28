//二分图最大匹配

/*
Problem Description
RPG girls今天和大家一起去游乐场玩，终于可以坐上梦寐以求的过山车了。可是，过山车的每一排只有两个座位，而且还有条不成文的规矩，
就是每个女生必须找个个男生做partner和她同坐。但是，每个女孩都有各自的想法，举个例子把，Rabbit只愿意和XHD或PQK做partner，Grass
只愿意和linle或LL做partner，PrincessSnow愿意和水域浪子或伪酷儿做partner。考虑到经费问题，boss刘决定只让找到partner的人去坐过
山车，其他的人，嘿嘿，就站在下面看着吧。聪明的Acmer，你可以帮忙算算最多有多少对组合可以坐上过山车吗？
Input
输入数据的第一行是三个整数K , M , N，分别表示可能的组合数目，女生的人数，男生的人数。0<K<=1000
1<=N 和M<=500.接下来的K行，每行有两个数，分别表示女生Ai愿意和男生Bj做partner。最后一个0结束输入。
Output
对于每组数据，输出一个整数，表示可以坐上过山车的最多组合数。
Sample Input
6 3 3
1 1
1 2
1 3
2 1
2 3
3 1
0
 */

//匈牙利算法
#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=505;
int line[N][N];//记录连接线
int girl[N],used[N];//girl表示女生被分配的男生，used表示女生被分配
int k,m,n;
bool found(int x)//递归查找
{
    for(int i=1; i<=n; i++)//遍历女生
    {
        if(line[x][i]&&!used[i])//如果当前男生 与 女生 i 有连接线
        {
            used[i]=1; //将该女生设置为占用状态
            if(girl[i]==0||found(girl[i]))//如果之前的女生就没被占用，或者之前占用该女生的男生能找到新的未被占用的女生，就可以将该女生设置为占用状态
            {
                girl[i]=x;//将该女生设置为占用状态
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int x,y;
    while(scanf("%d",&k)&&k)
    {
        scanf("%d %d",&m,&n);
        memset(line,0,sizeof(line));//记录连接线
        memset(girl,0,sizeof(girl));
        for(int i=0; i<k; i++)
        {
            scanf("%d %d",&x,&y);
            line[x][y]=1;
        }
        int sum=0;//匹配成功男生
        for(int i=1; i<=m; i++)//遍历男生
        {
            memset(used,0,sizeof(used));//每次遍历新的男生都要将used归零
            if(found(i)) sum++;//如果找到就累加
        }
        printf("%d\n",sum);
    }
    return 0;
}
