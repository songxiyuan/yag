/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */
#include <string>
using namespace std;
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (haystack.size() < needle.size())
            return -1;
        if (haystack == needle)
            return 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            if (haystack[i] == needle[0])
            {
                for (int j = 1; j < needle.size(); j++)
                {
                    if (needle[j] != haystack[i + j])
                    {
                        break;
                    }
                    if (j == needle.size() - 1)
                        return i;
                }
            }
        }
        for (int i = 0; i < needle.size(); i++)
        {
            if (needle[i] != haystack[i])
                return -1;
        }
        return 0;
    }
};

int main()
{
    Solution s;
    s.strStr("mississippi", "issip");
    return 0;
}


