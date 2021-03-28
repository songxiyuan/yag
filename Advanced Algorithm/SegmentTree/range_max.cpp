#include<vector>
#include<iostream>
#include<cstdio>
#include<algorithm>

//区间求和
using namespace std;

void updateFromSon(vector<int> &value,int pos)
{
    value[pos]=max(value[pos*2+1],value[pos*2+2]);
}

void build_segement_tree(vector<int> &value,vector<int> &nums,int pos,int left,int right)
{
    if(left==right)
    {
        value[pos]=nums[left];
        return;
    }
    int mid=(left+right)/2;
    build_segement_tree(value,nums,pos*2+1,left,mid);
    build_segement_tree(value,nums,pos*2+2,mid+1,right);
    updateFromSon(value,pos);
}


void print_segment_tree(vector<int> &value,int pos,int left,int right,int layer)
{
    for(int i=0;i<layer;i++)
    {
        printf("---");
    }
    printf("[%d %d][%d]:%d\n",left,right,pos,value[pos]);
    int mid=(left+right)/2;
    print_segment_tree(value,pos*2+1,left,mid,layer+1);
    print_segment_tree(value,pos*2+2,mid+1,right,layer+1);
}

int max_range_segment_tree(vector<int> &value, int pos,int left,int right,int qleft,int qright)
{
    if(qleft>right||qright<left)return 0;
    if(qleft<=left && qright>=right)
    {
        return value[pos];
    }
    int mid=(left+right)/2;
    return max(max_range_segment_tree(value,pos*2+1,left,mid,qleft,qright),max_range_segment_tree(value,pos*2+2,mid+1,right,qleft,qright));
}

void update_segment_tree(vector<int> &value,int pos,int left,int right,int index,int new_value)
{
    if(left==right && left==index)
    {
        value[pos]=new_value;
        return;
    }
    int mid=(left+right)/2;
    if(index<=mid)
    {
        update_segment_tree(value,pos*2+1,left,mid,index,new_value);
    }
    else
    {
        update_segment_tree(value,pos*2+2,mid+1,right,index,new_value);
    }
    updateFromSon(value,pos);
}

class NumArray
{
    public:
    vector<int> _value;
    int _right_end;
    NumArray(vector<int> nums)
    {
        if(nums.size()==0)return;
        int n=nums.size()*4;
        for(int i=0;i<n;i++)_value.push_back(0);
        build_segement_tree(_value,nums,0,0,nums.size()-1);
        _right_end=nums.size()-1;
    }
    void update(int i,int val)
    {
        update_segment_tree(_value,0,0,_right_end,i,val);
    }
    int maxRange(int i,int j)
    {
        return max_range_segment_tree(_value,0,0,_right_end,i,j);
    }
};

int main(){
	std::vector<int> nums={1,2,3,5,8,6,4};
	NumArray num_array(nums);
	printf("%d\n", num_array.maxRange(2, 6));
	// num_array.update(1, 2);
	// printf("%d\n", num_array.sumRange(0, 2));	
	return 0;
}
