/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 */


class Solution {
public:
    int findLHS(vector<int>& nums) {
         int res = 0;
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            m[nums[i]]++; //map可以不用判断之前有没有，直接++
        }
        map<int, int>::iterator it = m.begin(), pre;
        for(;it != m.end(); it++) {
            pre = prev(it);
            if(it->first == pre->first + 1) {
                res = max(res, it->second + pre->second);
            }
        }
        return res;
    }
};

