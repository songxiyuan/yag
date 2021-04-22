#include<iostream>
using namespace std;
const int N=13;
int f[N][1<<14],g[N];
int n,m,num;
const int P=100000000;
int dp(){
    f[0][0]=1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=g[i];j++){ 
            if((j|g[i])>g[i])continue;//状态不合法 
            if((j&(j<<1)))continue; //判断自己左边行吗？           
            for(int k=0;k<=g[i-1];k++)//判断自己上面行吗？
                if((j&k)==0) 
                        f[i][j]+=f[i-1][k],f[i][j]%=P;
        }
    }
}
int main(){
    cin>>m>>n;
    num=(1<<n);
    int x;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            cin>>x;
            if(x)g[i]+=(1<<(j-1));
        }
    dp();
    int ans=0;
    for(int i=0;i<=g[m];i++)
        ans+=f[m][i],ans%=P;
    cout<<ans<<endl;	  

/*
那么f[i][j]表示在前i行中（包括i）在j个状态下的最大方案数
易得f[i][j]=(f[i][j]+f[i-1][k])mod p（p=10^9，j是第i行的状态，k是第i-1行的状态）
2 3
1 1 1
0 1 0
 */

// 作者：lengxuenong 
// 来源：CSDN 
// 原文：https://blog.csdn.net/lengxuenong/article/details/79150592 
// 版权声明：本文为博主原创文章，转载请附上博文链接！