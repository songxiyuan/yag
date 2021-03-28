/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict;
        for(int i=0;i<wordDict.size();i++)dict.insert(wordDict[i]);
        vector<bool> f(s.size() + 1, false);
        f[0] = true;
        for (int i = 1; i <= s.size(); ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (f[j] && dict.find(s.substr(j, i - j)) != dict.end())
                {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[s.size()];
    }
}
;
