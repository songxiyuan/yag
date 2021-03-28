#include<string>
#include<iostream>
#include<math.h>

using namespace std;

int count(int N)
{
    int res=0;
    string strN=to_string(N);
    int L=strN.size();
    for(int i=0;i<L;i++)
    {
        if(i<L-1)
        {
            res+=(strN[i]-'0')*pow(9,(L-2-i))*8;
        }
        else
        {
            for(int j=N-N%10;j<N+1;j++)
            {   
                if(j%9>0)res+=1;
            }
        }
    }
    return res;
}

int my(int F,int L)
{
    return count(L)-count(F)+1;
}

int main()
{
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        int F,L;
        cin>>F>>L;
        cout<<"Case #"<<i<<": "<<my(F,L)<<endl;
    }
    return 0;
}

/*
2
0 16
88 102
 */