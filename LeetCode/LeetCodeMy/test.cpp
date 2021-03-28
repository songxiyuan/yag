/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */
#include<vector>
#include <algorithm> 
#include <iostream>

using namespace std;
class Solution {
public:

    // 用一个栈维护，递增的时候push进去，
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        int _max=0;
        vector<int> stack;
        stack.push_back(-1);
        int curIndex=0;
        while(curIndex<n)
        {
            while(stack.back()!=-1 && heights[stack.back()]>=heights[curIndex])
            {
                int a=heights[stack.back()];
                stack.pop_back();
                _max=max(_max,a*(curIndex -stack.back()-1));
                
            }
            stack.push_back(curIndex++);
        }
        while(stack.back()!=-1)
        {
            int a=heights[stack.back()];
            stack.pop_back();
            _max=max(_max,a*(n-stack.back()-1));
        }
        return _max;
    }
};

