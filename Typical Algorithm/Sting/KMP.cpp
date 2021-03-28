#include <iostream>
#include <string>
#include <iterator>//输出

using namespace std;
void Next(string str, int next[]){  //自己跟自己匹配
    int length=str.size(); 
    next[0]=-1;
    int j=-1;
    for(int i=1;i<length;i++){
        while(j>-1 && str[j+1]!=str[i]) j=next[j];
        if(str[j+1]==str[i]) j++;
        next[i]=j;
    }
}
void Match(string str1,string str2,int next[]){
    Next(str2,next);
    int length1=str1.size(),length2=str2.size();
    int j=-1;
    for(int i=0;i<length1;i++){
        while(j>-1 && str2[j+1]!=str1[i]) j=next[j];
        if(str2[j+1]==str1[i]) j++;
        if(j==length2-1){
            cout<<"Pattern occurs with shift "<<i-length2+1<<endl;
            j=next[j];
        }
    }
}
int main(){
   string str1="bbcabcdababcdabcdabde";
   string str2="abcdabd";
   int next[20];
   Match(str1,str2,next);
   copy(next,next+10,ostream_iterator<int>(cout," "));
   cout<<endl;
   return 0;
}