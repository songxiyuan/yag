//Count the number of prime numbers less than a non-negative number, n. 
//
// 
// Example 1: 
//
// 
//Input: n = 10
//Output: 4
//Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// 
//
// Example 2: 
//
// 
//Input: n = 0
//Output: 0
// 
//
// Example 3: 
//
// 
//Input: n = 1
//Output: 0
// 
//
// 
// Constraints: 
//
// 
// 0 <= n <= 5 * 106 
// 
// Related Topics Hash Table Math 
// 👍 2863 👎 747


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countPrimes(int n) {
        int res=0;
        for(int i=2;i<n;i++){
            if(isPrime_3(i))res++;
        }
        return res;
    }
    bool isPrime_3( int num )
    {
        //两个较小数另外处理
        if(num ==2|| num==3 )
            return 1 ;
        //不在6的倍数两侧的一定不是质数
        if(num %6!= 1&&num %6!= 5)
            return 0 ;
        int tmp =sqrt( num);
        //在6的倍数两侧的也可能不是质数
        for(int i= 5;i <=tmp; i+=6 )
            if(num %i== 0||num %(i+ 2)==0 )
                return 0 ;
        //排除所有，剩余的是质数
        return 1 ;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
