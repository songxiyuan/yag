// https://www.zhihu.com/question/49692292

#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 1005;
int bit[MAX_N << 2];
int x[MAX_N];
int n;

void add(int i, int x) {
    while (i <= n) {
        bit[i] += x;
        i += i&-i;
    }
}

int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i&-i;
    }
    return s;
}

int compress(int a[], int n) {
    vector<int> as;
    for (int i = 0; i < n; ++i) as.push_back(a[i]);
    sort(as.begin(), as.end());
    int m = unique(as.begin(), as.end()) - as.begin();
    for (int i = 0; i < n; ++i) {
        a[i] = find(as.begin(), as.begin() + m, a[i]) - as.begin() + 1;
    }
    return m;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        memset(bit, 0, sizeof(bit));
        scanf("%d", &n);
        int ans = 0;
        for (int i = 0; i < n; ++i) scanf("%d", x+i);
        compress(x, n);
        for (int i = 0; i < n; ++i) {
            ans += i - sum(x[i]);
            add(x[i], 1);
        }
        printf("Scenario #%d:\n%d\n\n", t, ans);
    }
}