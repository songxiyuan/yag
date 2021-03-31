//Given two strings s and t, determine if they are isomorphic. 
//
// Two strings s and t are isomorphic if the characters in s can be replaced to 
//get t. 
//
// All occurrences of a character must be replaced with another character while 
//preserving the order of characters. No two characters may map to the same charac
//ter, but a character may map to itself. 
//
// 
// Example 1: 
// Input: s = "egg", t = "add"
//Output: true
// Example 2: 
// Input: s = "foo", t = "bar"
//Output: false
// Example 3: 
// Input: s = "paper", t = "title"
//Output: true
// 
// 
// Constraints: 
//
// 
// 1 <= s.length <= 5 * 104 
// t.length == s.length 
// s and t consist of any valid ascii character. 
// 
// Related Topics Hash Table 
// 👍 1942 👎 461


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size(), m = t.size();
        if (n != m) return false;

        vector<int> mapping(255, -1), mapped(255, 0);

        for (int i = 0; i < n; i++) {
            if (mapping[s[i]] == -1)   //If character in s[i] is not yet mapped with any charecter
            {
                if (mapped[t[i]]) return false;     //If character s[i] is trying to map is already been mapped with another charecter return false
                //Else, map charecter s[i] with t[i]
                mapping[s[i]] = t[i];
                mapped[t[i]] = 1;
            } else if (mapping[s[i]] != t[i])//If already mapped charecter s[i] is trying to map with another charecter
                return false;
        }

        return true;

    }
//    //执行耗时:8 ms,击败了58.11% 的C++用户
//    //内存消耗:6.8 MB,击败了83.56% 的C++用户
//    bool isIsomorphic(string s, string t) {
//        unordered_map<char, int> strMap;//符号->位置
//        if (s.size() != t.size())return false;
//        for (int i = 0; i < s.size(); i++) {
//            if (strMap.find(s[i]) != strMap.end()) {
//                if (t[i] != t[strMap[s[i]]]) {
//                    return false;
//                }
//            }
//            strMap[s[i]] = i;
//        }
//        strMap.clear();
//        for (int i = 0; i < t.size(); i++) {
//            if (strMap.find(t[i]) != strMap.end()) {
//                if (s[i] != s[strMap[t[i]]]) {
//                    return false;
//                }
//            }
//            strMap[t[i]] = i;
//        }
//        return true;
//    }
};
//leetcode submit region end(Prohibit modification and deletion)
