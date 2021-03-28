#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        bool dp[1111][1111];
        memset(dp, false, sizeof dp);
        dp[0][0] = true;
        for(int i = 1; i < stones.size(); i++) {
            for(int j = 0; j < i; j++) {
                int dis = stones[i] - stones[j];
                if(dis >= 1110) continue;
                if(dp[j][dis] || dp[j][dis + 1] || (dis > 0 && dp[j][dis - 1])) {
                    dp[i][dis] = true;
                }
            }
        }
        for(int i = 0; i < stones.size(); i++){
            if(dp[stones.size() - 1][i])
                return true;
        }
        return false;
    }
};

int main()
{
    Solution a;
    vector<int> s={0,1,3,5,6,8,12,17};
    a.canCross(s);
    return 0;
}