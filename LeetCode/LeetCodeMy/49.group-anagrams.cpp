/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> orderstrs(strs);
        vector<int> marks(strs.size(),0);
        int markK=0;
        map<string,int> dic;
        for(int i=0;i<orderstrs.size();i++)
        {
            sort(orderstrs[i].begin(),orderstrs[i].end());
            auto f=dic.find(orderstrs[i]);
            if(f==dic.end())
            {
                dic.insert(pair<string,int>(orderstrs[i],markK));
                marks[i]=markK++;
            }
            else
            {
                marks[i]=f->second;
            }
        }
        vector<vector<string>> res(markK,vector<string>(0));
        for(int i=0;i<marks.size();i++)
        {
            res[marks[i]].push_back(strs[i]);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> strs={"eat","tea","tan","ate","nat","bat"};
    s.groupAnagrams(strs);
    return 0;
}

