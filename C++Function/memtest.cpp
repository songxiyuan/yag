#include<iostream>

using namespace std;

void my(int** shuzu)
{
    // int* shuzu = *s;
    *shuzu = new int[10];
    for(int i=0;i<10;i++)
    {
        *shuzu[i]=i;
    }
    for(int i=0;i<10;i++)
    {
        cout<<shuzu[i]<<endl;
    }
}


int fun(register int arg)
{


}

int main()
{
    int** shuzu;
    my(shuzu);
    for(int i=0;i<10;i++)
    {
        cout<<shuzu[i]<<endl;
    }
    return 0;
}