class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for(int i = 3; i < n + 1; ++i){ //n以内所有长度绳子的情况
            for(int j = 1; j < i - 1; ++j){ //可选择剪的长度
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));    
            }
        }
        return dp[n];
    }
};