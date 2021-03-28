// greater 和 less 


#include <iostream>
#include <algorithm>
#include <functional>
 
using namespace std;
 
int main()
{
	int nums[] = {5, 3, 1, 2, 4};
    int length = sizeof(nums)/sizeof(int);	
	std::cout << "nums length is " << length << std::endl;
	sort(nums, nums + length, greater<int>());
	for (int i = 0; i < length; ++i)
	{
		std::cout << nums[i] << "\t";	
	}
	std::cout << std::endl;
	sort(nums, nums + length, less<int>());
	for (int i = 0; i < length; ++i)
	{
		std::cout << nums[i] << "\t";	
	}
	std::cout << std::endl;
	return 0;
}


// 自定义比较！！！
struct student{
    int ID;
    int Age;
    int Score;
};
student stu [3] = {
    {1, 18, 88},
    {2, 19, 90},
    {3, 20, 70}
};
bool comparator(const student &a, const student &b)
{
    return (a.Score < b.Score);
}

int bijiaoqi()
{
    sort(stu, stu + 3, comparator);
    for(int i = 0; i < 3; i++)
        cout << stu[i].ID << ' ' << stu[i].Age << ' ' << stu[i].Score << endl;
    return 0;
}