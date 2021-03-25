#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
void max_min();

int main(){
    max_min();
}

void max_min(){
    //max min
    int a[3]={1,2,3};
    int maxNum=max(1,2);
    vector<int> b(a,a+3);
    int *maxNum2;
    maxNum2=max_element(a,a+3);
    cout<< *maxNum2;
    cout<<endl;
    auto maxNum3=max_element(b.begin(),b.end());
    int maxNum4=*max_element(b.begin(),b.end());
    cout<<*maxNum3;
    cout<<maxNum4;
}