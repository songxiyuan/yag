/* 
有 N 件物品和一个容量为 V 的背包。放入第 i 件物品耗费的费用是 Ci1，得到的
价值是 Wi。求解将哪些物品装入背包可使价值总和最大。 

个数 背包大小
物品费用，耗费体积
价值

第一行有两个整数 N V 用空格隔开，分别表示物品组数和背包容量。
接下来有 N 组数据：
每组数据第一行有一个整数 Si表示第 i ii 个物品组的物品数量；
每组数据接下来有 Si 行，每行有两个整数 用空格隔开，分别表示第 i ii 个物品组的第 j jj 个物品的体积和价值；
3 5
2
1 2
2 4
1
3 4
1
4 5


答案 8
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110;
int n, m;
int f[N],v[N], w[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++ ) {
        int s;
        cin >> s;
        for (int j = 0; j < s; j ++ ) cin >> v[j] >> w[j];
        for (int j = m; j >= 0; j --)
            for (int k = 0; k < s; k ++ )
                if(j >= v[k])
                    f[j] = max (f[j], f[j - v[k]] + w[k]);
    }
    cout << f[m] << endl;
    return 0;
}