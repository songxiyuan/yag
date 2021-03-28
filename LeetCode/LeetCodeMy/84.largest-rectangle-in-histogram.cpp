/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */
#include<vector>
#include <algorithm> 
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
class Solution0 {
public:

    // 用一个栈维护，递增的时候push进去，
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        int _max=0;
        vector<int> stack;
        stack.push_back(-1);
        int curIndex=0;
        while(curIndex<n)
        {
            while(stack.back()!=-1 && heights[stack.back()]>=heights[curIndex])
            {
                int a=heights[stack.back()];
                stack.pop_back();
                _max=max(_max,a*(curIndex -stack.back()-1));
                
                
            }
            stack.push_back(curIndex++);
        }
        while(stack.back()!=-1)
        {
            int a=heights[stack.back()];
            stack.pop_back();
            _max=max(_max,a*(n-stack.back()-1));
        }
        return _max;
    }
};


//方法二

typedef long long ll;
const int N = 100000 + 10, INF = 0x3f3f3f3f;
 
struct node
{
    int index;
    int value;
    int parent;
    int child[2];
 
    friend bool operator< (node a, node b)
    {
        return a.index < b.index;
    }
 
    void init(int _index, int _value, int _parent)
    {
        index = _index;
        value = _value;
        parent = _parent;
 
        child[0] = child[1] = 0;
    }
 
} tree[N];
 
int root;
int top, stk[N];
ll ans;
 
//创建笛卡尔树
int cartesian_build(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int k = i - 1;
 
        //一直找到比i位置小的位置k
        while (tree[k].value > tree[i].value)
            k = tree[k].parent;
 
        //printf("i(%d - %d) k(%d - %d)\n", i, tree[i].value, k, tree[k].value);
 
        //将父节点的右子树放到自己的左子树上
        tree[i].child[0] = tree[k].child[1];
        //父节点的右子树重新指向
        tree[k].child[1] = i;
        //设置i的父节点
        tree[i].parent = k;
        //很多人没加这句，父节点关系就会乱掉
        tree[tree[i].child[0]].parent = i;
    }
 
    return tree[0].child[1];
}
 
int dfs(int x)
{
    if (!x)
        return 0;
    //计算最大值
    int sz = dfs(tree[x].child[0]);
    sz += dfs(tree[x].child[1]);
    ans = max(ans, (ll)(sz + 1) * tree[x].value);
    return sz + 1;
}
 
int main()
{
    int n, height;
    //freopen("test.txt", "r", stdin);
 
    while (scanf("%d", &n), n)
    {
        tree[0].init(0, 0, 0);
 
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &height);
            //初始化每个节点
            tree[i].init(i, height, 0);
        }
 
        //创建笛卡尔树
        root = cartesian_build(n);
        //
        ans = 0;
        dfs(root);
        printf("%lld\n", ans);
    }
 
    return 0;
}


/*

7 2 1 4 5 1 3 3 
2 1 5 6 2 3
4 1000 1000 1000 1000 
0

*/