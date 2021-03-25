#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int longestWPI(vector<int> &hours)
    {
        const int n = hours.size();
        for (int &v : hours)
            v = v > 8 ? 1 : -1;
        int s = 0;
        unordered_map<int, int> idx;
        int ans = 0;
        for (int i = 0; i < hours.size(); ++i)
        {
            s += hours[i];
            if (s > 0)
                ans = i + 1;
            if (!idx.count(s))
                idx[s] = i;
            if (idx.count(s - 1))
                ans = max(ans, i - idx[s - 1]); //如果
        }
        return ans;
    };
};

int main()
{
    Solution s;
    vector<int> temp;
    temp.push_back(6);
    temp.push_back(9);
    temp.push_back(9);
    temp.push_back(6);
    temp.push_back(9);
    temp.push_back(6);
    temp.push_back(6);
    s.longestWPI(temp);
    return 0;
}

#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#define MAX 10001
using namespace std;
int w[MAX], v[MAX], dp[MAX][MAX];

int main()
{

    int t;
    cin >> t;
    while (t-- > 0)
    {
        int N, X;
        cin >> N >> X;
        for (int i = 0; i < N; i++)
        {
            cin >> v[i] >> w[i];
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i < 3; i++)
        {
            for (int j = 1; j <= X; j++)
            {
                if (j < w[i])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
        cout << dp[N - 1][X] << endl;
    }
    return 0;
}

#include <iostream>
#include <string>
#include <map>

using namespace std;
int main()
{
    int N, M;
    while (cin >> N >> M)
    {
        map<string, string> m;
        for (int i = 0; i < N; i++)
        {
            string k, v;
            cin >> k >> v;
            m[k] = v;
        }
        for (int i = 0; i < M; i++)
        {
            string k;
            cin >> k;
            cout << m[k] << endl;
        }
    }
    return 0;
}

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

int price[1000];
int lovemore[1000];

void dfs(int nengnajige, int less, int &r, map<int, int> &m)
{
    if (less == 0)
    {
        r++;
        return;
    }
}

int main()
{
    int N, M;
    while (cin >> N >> M)
    {
        memset(price, 0, sizeof(price));
        memset(lovemore, 0, sizeof(lovemore));
        for (int i = 0; i < M; i++)
        {
            cin >> price[i];
        }
        int loveNum;
        cin >> loveNum;
        map<int, int> m; //序号 价格
        for (int i = 0; i < loveNum; i++)
        {
            cin >> lovemore[i];
            m[i] = lovemore[i]; //喜爱程序序号：喜爱的商品是哪个编号
        }
        int r = 0;
        int qujige[1000];
    }
    return 0;
}