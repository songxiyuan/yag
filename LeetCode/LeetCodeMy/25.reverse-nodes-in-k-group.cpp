/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
#include<vector>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
class Solution {
public:
    
    //输入第一个位置，和数字K，返回调整后的第一个
    ListNode reverse(ListNode* first, int k)
    {
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode result(0);

        return result.next;
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int r=1;
        int pre=nums[0];
        vector<int>::iterator it;
        for(it=nums.begin();it!=nums.end();it++)
        {
            if(it.!=pre)
            {
                pre=nums[i];
                r++;
            }
            else
            {
                nums.erase(it);
            }
        }
        return r;
    }
};


int main()
{
    Solution s;
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    ListNode f(6);
    ListNode g(7);
    a.next=&b;
    b.next=&c;
    c.next=&d;
    d.next=&e;
    e.next=&f;
    f.next=&g;

    ListNode* n=s.reverseKGroup(&a,3);
    while(n)
    {
        cout<<n->val<<endl;
        n=n->next;
    }
    return 0;
}

