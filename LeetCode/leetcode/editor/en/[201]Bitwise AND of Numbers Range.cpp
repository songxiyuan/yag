//Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND o
//f all numbers in this range, inclusive. 
//
// Example 1: 
//
// 
//Input: [5,7]
//Output: 4
// 
//
// Example 2: 
//
// 
//Input: [0,1]
//Output: 0 Related Topics Bit Manipulation 
// 👍 1280 👎 141


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int curr = m & n;
        if (m == n) {
            return curr;
        }
        //从最小数字的最高位开始以此判断
        //如果不相同，则不再向下走
        //1.先求最小数字最高位
        int res=0;
        int maski;
        long bit=1;
        for(int i=62;i>0;i--){
            maski=i;
            if(((bit<<i)&n)>0)break;
        }
        for(int i=maski;i>=0;i--){
            long mask=(1<<i);
            if((mask&m)!=(mask&n))break;//如果这位都是0，就break
            res|=mask&m;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
