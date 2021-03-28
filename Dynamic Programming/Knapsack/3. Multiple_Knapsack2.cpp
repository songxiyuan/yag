/* 
有 N 件物品和一个容量为 V 的背包。放入第 i 件物品耗费的费用是 Ci1，得到的
价值是 Wi。求解将哪些物品装入背包可使价值总和最大。 

个数 背包大小
物品费用，耗费体积
价值
5 10
3 6 5 2 8
5 15 9 2 16

*/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

#define M 10005
using namespace std;

// // // 优化空间复杂度
// // void knapsack01_spaceopt()
// // {
// //     int n,Vmax;
// //     cin>>n>>Vmax;

// //     vector<int> dp(Vmax+1,0);
// //     vector<int> Cost(Vmax+1,0);
// //     vector<int> Worth(Vmax+1,0);
// //     for(int i=1;i<=n;i++)
// //     {
// //         cin>>Cost[i];
// //     }
// //     for(int i=1;i<=n;i++)
// //     {
// //         cin>>Worth[i];
// //     }

// //     //dp开始都为0
// //     for(int i=1;i<=n;i++)//注意从1开始 并且是等于
// //     {
// //         for(int v=Cost[i];v<=Vmax;v++) //注意从Vmax开始 这要求在每次主循环中我们以 v ← V . . . 0 的递减顺序计算 F[v]，这样才能保证计算 F[v] 时 F[v v Ci] 保存的是状态 F[i i 1, v v Ci] 的值
// //         {
// //             dp[v] = max(dp[v],dp[v-Cost[i]]+Worth[i]);
// //         }
// //     }
// //     cout<<dp[Vmax];
// // }


// int main()
// {
//     cout<<"start"<<endl;
//     knapsack01_spaceopt();
//     return 0;
// }