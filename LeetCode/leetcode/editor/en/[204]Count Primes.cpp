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
        vector<bool> sieve=vector<bool>(n,false);
        int count=0;
        for(int i=2;i<n;i++){
            if(sieve[i])continue;
            count++;
            for(int j=2;j*i<n;j++)sieve[j*i]=true;
        }
        return count;
    }
//    int countPrimes(int n) {
//        bool sieve[n+1];
//        memset(sieve, false, sizeof(sieve));
//        int count=0;
//        for(int i=2;i<n;i++){
//            if(sieve[i])continue;
//            count++;
//            for(int j=2;j*i<n;j++)sieve[j*i]=true;
//        }
//        return count;
//    }
};
//leetcode submit region end(Prohibit modification and deletion)
