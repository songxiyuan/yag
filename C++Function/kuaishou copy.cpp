#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

void fullwater(vector<vector<int> >&juzhen,int id,vector<int>& res)
{
    res[id]=1;
    for(int i=id+1;i<juzhen.size();i++)
    {
        if(juzhen[id][i]==1)fullwater(juzhen,i,res);
    }

}

void clearwater(vector<vector<int> >&juzhen,int id,vector<int>& res)
{
    res[id]=0;
    for(int i=id-1;i>0;i--)
    {
        if(juzhen[id][i]==1)clearwater(juzhen,i,res);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<vector<int> >juzhen(N+1,vector<int>(N+1,0));
    for(int n=0;n<N-1;n++)
    {
        int a,b;
        cin>>a>>b;
        juzhen[a][b]=1;
        juzhen[b][a]=1;
    }
    int optnum;
    cin>>optnum;
    vector<int>res(N+1,0);;
    for(int o=0;o<optnum;o++)
    {
        int opt,obj;
        cin>>opt>>obj;
        if(opt==1)//full water
        {
            fullwater(juzhen,obj,res);
        }
        else if(opt==2)//clear water
        {
            clearwater(juzhen,obj,res);
        }
        else if(opt==3)//quary
        {
            cout<<res[obj]<<endl;
        }
    }
    return 0;
}


/*

5
1 2
5 1
2 3
4 2
12
1 1
2 3
3 1
3 2
3 3
3 4
1 2
2 4
3 1
3 3
3 4
3 5

 */