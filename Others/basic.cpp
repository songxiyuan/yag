#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MSIZE=9;


int 二分1(int (&m)[MSIZE],int num){//注意右值能不能取到,这里的右值可以取到
    int left=0;
    int right=sizeof(m)/sizeof(m[0])-1;
    while(left<right){
        int mid=left+(right-left)/2;//i+(j-i)/2；防止溢出
        if(m[mid]>=num){//注意重复出现的数字，这里能避免
            right=mid;
        }else{
            left=mid+1;//注意这里要加一，不然会陷入死循环
        }
    }
    return m[left];
}

int 二分2(int (&m)[MSIZE],int num,int left,int right){
    if(left==right){
        return m[left];
    }
    int mid=left+(right-left)/2;
    if(m[mid]>=num){//!!!
        return 二分2(m,num,left,mid);
    }else{
        return 二分2(m,num,mid+1,right);
    }
}
void 二分法(){
    //数组排序！
    int m[MSIZE] ={3,4,8,1,3,11,4,15,16};
    sort(m,m+sizeof(m)/sizeof(m[0]));
    for(auto i:m){
        cout<<i<<" ";
    }
    cout<<endl;

//    二分法查找第一个>=该数的位置
    cout<<二分1(m,4)<<endl;
    cout<<二分2(m,4,0,sizeof(m)/sizeof(m[0])-1);
}

int main(){
    二分法();
    return 0;
}