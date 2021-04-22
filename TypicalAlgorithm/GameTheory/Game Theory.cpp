//巴什博弈
//只有一堆n个物品，两个人轮流从中取物，规定每次最少取一个，最多取m个，最后取光者为胜。
// 胜负只与数量有关
#include <iostream>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
      if(n%(m+1)==0)  cout<<"后手必胜"<<endl;
      else cout<<"先手必胜"<<endl;//每次 两人拿到的总和为m+1即可
    return 0;
}

/*
威佐夫博弈（Wythoff Game）：

有两堆各若干的物品，两人轮流从其中一堆取至少一件物品，至多不限，或从两堆中同时取相同件物品，规定最后取完者胜利。
直接说结论了，若两堆物品的初始值为（x，y），且x<y，则另z=y-x；
记w=（int）[（（sqrt（5）+1）/2）*z  ]；
若w=x，则先手必败，否则先手必胜。

//没看懂

 */
 
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int n1,n2,temp;
    while(cin>>n1>>n2)
    {
        if(n1>n2)  swap(n1,n2);
        temp=floor((n2-n1)*(1+sqrt(5.0))/2.0);
        if(temp==n1) cout<<"后手必胜"<<endl;
        else cout<<"先手必胜"<<endl;
    }
    return 0;
}

/*
尼姆博弈（Nimm Game）：

尼姆博弈指的是这样一个博弈游戏：有任意堆物品，每堆物品的个数是任意的，双方轮流从中取物品，每一次只能从一堆物品中取部分或全部物品，最少取一件，取到最后一件物品的人获胜。

结论就是：把每堆物品数全部异或起来，如果得到的值为0，那么先手必败，否则先手必胜。

 */
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int n,ans,temp;
    while(cin>>n)
    {
        temp=0;
        for(int i=0;i<n;i++)
        {
            cin>>ans;
            temp^=ans;
        }
        if(temp==0)  cout<<"后手必胜"<<endl;
        else cout<<"先手必胜"<<endl;
    }
    return 0;
}

/*
 斐波那契博弈：

有一堆物品，两人轮流取物品，先手最少取一个，至多无上限，但不能把物品取完，之后每次取的物品数不能超过上一次取的物品数的二倍且至少为一件，取走最后一件物品的人获胜。

结论是：先手胜当且仅当n不是斐波那契数（n为物品总数）
 */
#include <iostream>  
#include <string.h>  
#include <stdio.h>  
using namespace std;  
const int N = 55;    
int f[N];   
void Init()  
{  
    f[0] = f[1] = 1;  
    for(int i=2;i<N;i++)  
        f[i] = f[i-1] + f[i-2];  
}    
int main()  
{  
    Init();  
    int n;  
    while(cin>>n)  
    {  
        if(n == 0) break;  
        bool flag = 0;  
        for(int i=0;i<N;i++)  
        {  
            if(f[i] == n)  
            {  
                flag = 1;  
                break;  
            }  
        }  
        if(flag) puts("Second win");  
        else     puts("First win");  
    }  
    return 0;  
}

