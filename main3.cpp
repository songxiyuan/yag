#include <iostream>
#include <vector>
#include <stack>
#include <deque>

using namespace std;

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
        cout<<res;
        return res;
    }
};



int main() {
    Solution s;
    s.rangeBitwiseAnd(10, 11);
    cout << "Hello, World!" << std::endl;
    return 0;
}
