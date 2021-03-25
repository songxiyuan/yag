//Write an algorithm to determine if a number n is happy. 
//
// A happy number is a number defined by the following process: 
//
// 
// Starting with any positive integer, replace the number by the sum of the squa
//res of its digits. 
// Repeat the process until the number equals 1 (where it will stay), or it loop
//s endlessly in a cycle which does not include 1. 
// Those numbers for which this process ends in 1 are happy. 
// 
//
// Return true if n is a happy number, and false if not. 
//
// 
// Example 1: 
//
// 
//Input: n = 19
//Output: true
//Explanation:
//12 + 92 = 82
//82 + 22 = 68
//62 + 82 = 100
//12 + 02 + 02 = 1
// 
//
// Example 2: 
//
// 
//Input: n = 2
//Output: false
// 
//
// 
// Constraints: 
//
// 
// 1 <= n <= 231 - 1 
// 
// Related Topics Hash Table Math 
// 👍 2969 👎 493


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isHappy(int n) {
        int n0 = n;
        int map[10];
        for(int i=0;i<10;i++){
            map[i]=0;
        }
        while (true) {
            if (n<10 && map[n]==1)return true;
            if (n<10){
                map[n]=1;
            }
            int tempn = n;
            n = 0;
            while (tempn > 0) {
                n += (tempn % 10) * (tempn % 10);
                tempn/=10;
            }
            if (n == 1)return true;
            if (n0 == n)return false;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
//总结，没有捷径，规律难找
