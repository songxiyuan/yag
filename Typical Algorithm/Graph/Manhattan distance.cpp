#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


//poj 2926

const int INF = 1e18;
const int maxn = 1e5 + 5;
int a[maxn][8]; // a[i][j] 代表第i个点在j维的坐标
int n, k = 5;  // 维数
int cal() {
    int ans = 0, mi, mx, t;
    for (int s = 0 ; s < (1<<k) ; s ++) {
        mi = INF, mx = -INF;
        for (int i = 1 ; i <= n ; i++) {
            t = 0;//计算得到的值
            for (int j = 0 ; j < k ; j++) { // 为了二进制的方便就从0开始存
                if ((1<<j) & s) t += a[i][j];
                else t -= a[i][j];
            }
            mi = min(mi, t);
            mx = max(mx, t);
        }
        ans = max(ans, mx-mi);
    }
    return ans;
}
void solve() {
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; i++) {
        for (int j = 0 ; j < k ; j ++) {
            scanf("%lf", &a[i][j]);
        }
    }
    printf("%.2f\n", cal());
}


//LeetCode 1131
// Given two arrays of integers with equal lengths, return the maximum value of:
// |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
// where the maximum is taken over all 0 <= i, j < arr1.length.


class Solution {
public:
    int maxAbsValExpr(vector<int>& x, vector<int>& y) {
        int res = 0, n = x.size(), closest, cur;
        for (int p : {1, -1}) {
            for (int q : {1, -1}) {
                closest = p * x[0] + q * y[0] + 0;//最起始点为 0，
                for (int i = 1; i < n; ++i) {
                    // cur = p * x[i] + q * y[i] + i;//当前点
                    cur = p * x[i] + q * y[i];//当前点
                    res = max(res, cur - closest);// 上次的最大值跟这次对比点的值比较，取最大
                    closest = min(closest, cur);// 最小点取，前一次最近点和当前点
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> x={0,0,10};
    vector<int> y={0,1,0};
    Solution s;
    s.maxAbsValExpr(x,y);
    return 0;
}