#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>

using namespace std;
int main()
{
// 在从小到大的排序数组中，
// lower_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于或等于num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
// upper_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个大于num的数字，找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
    int num[6]={1,2,4,7,15,34}; 
	cout<<"asdfads"<<endl;
	sort(num,num+6);                           //按从小到大排序 
	int pos1=lower_bound(num,num+6,7)-num;    //返回数组中第一个大于或等于被查数的值 
	int pos2=upper_bound(num,num+6,7)-num;    //返回数组中第一个大于被查数的值
    int* pos3=lower_bound(num,num+6,7);  
	cout<<pos1<<" "<<num[pos1]<<endl;
	cout<<pos2<<" "<<num[pos2]<<endl;
    cout<<*pos3<<endl;

    system("PAUSE");
    return 0;
}



int reverse()
{
/**
逆转元素次序
    reverse(beg,end)
    reverse_copy(sourceBeg,sourceEnd,destBeg)
    reverse()会将区间[beg,end)内的元素全部逆序；
    reverse_copy()会将源区间[sourceBeg,sourceEnd)内的元素复制到"以destBeg起始的目标区间"，并在复制过程中颠倒安置次序；
    reverse_copy()返回目标区间内最后一个被复制元素的下一个位置，也就是第一个未被覆盖的元素；
    调用者必须保证目标区间足够大，要不就得使用插入型迭代器
 */
	int a[50];
	int b[50]; 
	for(int i=0;i<10;i++)
	{
		a[i]=i;
		if(i!=9)
		cout<<a[i]<<" ";
		else
		cout<<a[i]<<endl;
	}
	reverse(a,a+10);         //第二个参数是数组最后一个元素的下一个地址 
	for(int i=0;i<10;i++)
	{
		if(i!=9)
		cout<<a[i]<<" ";
		else
		cout<<a[i]<<endl;
	}
	reverse_copy(a,a+10,b); //倒序放入b数组中 
	for(int i=0;i<10;i++)
	{
		if(i!=9)
		cout<<b[i]<<" ";
		else
		cout<<b[i]<<endl;
	}
}


///string 转 int
int main2()
{
	string s1 = "2147482", s2 = "-214748";
	string s3 = "214748666666663", s4 = "-21474836488";
	cout << stoi(s1) << endl;
	cout << stoi(s2) << endl;
	cout << atoi(s3.c_str()) << endl;
	cout << atoi(s4.c_str()) << endl;

	//int 转 string
	string pi = "pi is " + to_string(3.1415926);  

	return 0;
}