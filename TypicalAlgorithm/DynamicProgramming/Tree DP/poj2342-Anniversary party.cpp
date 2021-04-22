// https://blog.csdn.net/iwts_24/article/details/82185393

#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<queue>
#include<sstream>
#include<iterator>
#include<math.h>
#include<malloc.h>
#include<string.h>
#include<stack>
#define TIME std::ios::sync_with_stdio(false)
#define LL long long
#define MAX 6100
#define INF 0x3f3f3f3f
 
using namespace std;
 
int N;
int dp[MAX][2], father[MAX], step[MAX];
 
int Max(int a, int b) {
    return a > b ? a : b;
}
 
void init() {
    memset(dp, 0, sizeof(dp));
    memset(father, 0, sizeof(father));
    memset(step, 0, sizeof(step));
}
 
void dp_tree(int node) {
    step[node] = 1;
    for (int i = 1; i <= N; i++) {
        if (father[i] != node || step[i] == 1 ) continue;//如果其父亲不是node, 或者已经被访问过，就跳过
        dp_tree(i);
        dp[node][1] += dp[i][0];
        dp[node][0] += Max(dp[i][0], dp[i][1]);
        // dp[上司][来] += dp[下属][不来]; 
        // dp[上司][不来] += Max(dp[下属][来],dp[下属][不来]);  默认存储 来 的值
    }
}
 
int main() {
    TIME;
    while (scanf("%d",&N) != EOF) {
        init();
        for (int i = 1; i <= N; i++) {
            scanf("%d",&dp[i][1]);
        }
        int l, k;
        while (scanf("%d%d",&l,&k) != EOF) {
            if (l == 0 && k == 0) break;
            father[l] = k;
        }
        int root = 0;
        for (int i = 1; i <= N; i++) {
            if (father[i] != 0) continue;//父亲为0的人为root
            root = father[i];
            break;
        }
        dp_tree(root);
        int ans = Max(dp[root][0], dp[root][1]);
        printf("%d\n",ans);
    }
 
    system("pause");
    return 0;
}

/*

Employees are numbered from 1 to N. A first line of input contains a number N. 1 <= N <= 6 000. Each of the subsequent N lines contains the conviviality rating of the corresponding employee. Conviviality rating is an integer number in a range from -128 to 127. After that go N – 1 lines that describe a supervisor relation tree. Each line of the tree specification has the form: 
L K 
It means that the K-th employee is an immediate supervisor of the L-th employee. Input is ended with the line 
0 0 

7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5
0 0

output 
5

 */