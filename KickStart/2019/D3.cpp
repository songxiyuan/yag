#include<vector>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;

int my(int k,map<int,int> m)
{
    
}

int main()
{
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        int K,N;
        vector<int> X(N,0);
        vector<int> C(N,0);

        for(int j=0;j<N;j++)
        {
            cin>>X[j];
        }
        for(int j=0;j<N;j++)
        {
            cin>>C[j];
        }
        map<int,int> m;
        for(int j=0;j<N;j++)
        {
            m[X[j]]=C[j];
        }
        cout<<"Case #"<<i<<": "<<my(K,m)<<endl;
    }
    return 0;
}