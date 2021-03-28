// P2622 关灯问题II
/*
现有n盏灯，以及m个按钮。每个按钮可以同时控制这n盏灯——按下了第i个按钮，对于所有的灯都有一个效果。按下i按钮对于第j盏灯，是下面3中效果之一：如果a[i][j]为1，那么当这盏灯开了的时候，把它关上，否则不管；如果为-1的话，如果这盏灯是关的，那么把它打开，否则也不管；如果是0，无论这灯是否开，都不管。

现在这些灯都是开的，给出所有开关对所有灯的控制效果，求问最少要按几下按钮才能全部关掉。
输入输出格式
输入格式：
前两行两个数，n m
接下来m行，每行n个数,a[i][j]表示第i个开关对第j个灯的效果。
输出格式：
一个整数，表示最少按按钮次数。如果没有任何办法使其全部关闭，输出-1

https://www.cnblogs.com/Tony-Double-Sky/p/9283254.html
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;


const int maxn = 2048;
int num, m, numd;

int vis[maxn];
int map[maxn][maxn];

struct Node
{
    int dp, step;
};

//广度优先搜索 用来求得最小次数
void BFS(int n)
{
    queue<Node> Q;
    Node fir;
    fir.step = 0, fir.dp = n; //初始状态入队
    Q.push(fir);
    while (!Q.empty())
    { //BFS
        Node u = Q.front();
        Q.pop();
        int pre = u.dp;
        //枚举每个操作
        for (int i = 1; i <= m; i++)
        { 
            int now = pre;
            for (int j = 1; j <= num; j++)
            {
                if (map[i][j] == 1)
                {
                    if ((1 << (j - 1)) & now)
                    {
                        now = now ^ (1 << (j - 1)); //对状态进行操作
                    }
                }
                else if (map[i][j] == -1)
                {
                    now = ((1 << (j - 1)) | now); //对状态进行操作
                }
            }
            fir.dp = now, fir.step = u.step + 1; //记录步数
            if (vis[now] == true)
            {
                continue;
            }
            if (fir.dp == 0)
            {                             //达到目标状态
                vis[0] = true;            //相当于一个标记flag
                cout << fir.step << endl; //输出
                return;                   //退出函数
            }
            Q.push(fir);     //新状态入队
            vis[now] = true; //表示这个状态操作过了（以后在有这个状态就不用试了）
        }
    }
}

// 3
// 2
// 1 0 1
// -1 1 0


int main()
{
    cin>>num;
    cin>>m;
    int n = (1 << (num)) - 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            int temp;
            cin>>temp;
            map[i][j]=temp;
        }
    }
    BFS(n);
    if (vis[0] == false)
        cout << -1 << endl;
    return 0;
}