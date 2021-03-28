/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include<string>
#include<unordered_map>
using namespace std;
// class Solution暴力破解{
// public:
//     int lengthOfLongestSubstring(string s) {
//         int len = s.length();
//         string str;//表示最长子串
//         int max_len = 0;
//         for(int i = 0; i < len; i++)
//         {
//             string t_str;//中间变量;
//             unordered_map<char,int> _map;
//             unordered_map<char,int>::iterator it;
//             for(int j = i ; j < len; j++)
//             {
//                 it = _map.find(s[j]);
//                 if(it == _map.end())
//                 {
//                      t_str = t_str + s[j];
//                     _map.insert(pair<char,int>(s[j],1));
//                     if(t_str.length() > max_len)
//                      max_len = t_str.length();
//                 }
//                 else
//                     break;
//             }
//         }
//         return max_len;
 
//     }
// };
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //use hashtable to store the last position of this characters
        if(s.length()==0)return 0;
        int pos[256];
        int maxLength=1;
        memset(pos,-1,sizeof(pos));
        int cur_len=0;
        for(int i=0;i<s.length();i++)
        {
            if(pos[s[i]]==-1 || i-pos[s[i]]>cur_len)
            {
                cur_len++;
            }
            else
            {
                cur_len=i-pos[s[i]];
            }
            pos[s[i]]=i;//updata the recorde position of now character
            if(cur_len>maxLength)maxLength=cur_len;
        }
        return maxLength;
    }
};

