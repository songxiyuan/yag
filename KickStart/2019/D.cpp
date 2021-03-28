#include<vector>
#include<iostream>
#include<cstdio>
#include<algorithm>

//区间求和
using namespace std;

void updateFromSon(vector<int> &value,int pos)
{
    value[pos]=(value[pos*2+1]^value[pos*2+2]);
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

int xor_range_segment_tree(vector<int> &value, int pos,int left,int right,int qleft,int qright)
{
    if(qleft>right||qright<left)return 0;
    if(qleft<=left && qright>=right)
    {
        return value[pos];
    }
    int mid=(left+right)/2;
    return xor_range_segment_tree(value,pos*2+1,left,mid,qleft,qright)^xor_range_segment_tree(value,pos*2+2,mid+1,right,qleft,qright);
}


bool jige1(int x){  
    x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1);  
    x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2);  
    x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4);  
    x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8);  
    x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16);  
    return x%2==0;
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
    int my()
    {
        for(int r=_right_end;r>=0;r--)
        {
            for(int i=0;i<=_right_end;i+=r)
            {
                int x=xor_range_segment_tree(_value,0,0,_right_end,i,i+r);
                if(jige1(x))return r+1;
            }
        }
        return 0;
    }
};


int main()
{
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        int N,Q;
        cin>>N>>Q;
        vector<int> A(N,0);
        vector<int> res(Q,0);
        for(int j=0;j<N;j++)
        {
            cin>>A[j];
        }
        
        NumArray num_array(A);
        //查询
        int P,V;
        for(int k=0;k<Q;k++)
        {
            cin>>P>>V;
            num_array.update(P, V);
            res[k]=num_array.my();
           
        }
        cout<<"Case #"<<i<<":";
        for(int k=0;k<Q;k++)
        {
            cout<<" "<<res[k];
        }
        cout<<endl;
    }
    return 0;
}

/*

1
1 1
1
0 3


1
2 1
1 1
1 2


 */