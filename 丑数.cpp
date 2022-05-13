class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int i = 0, j = 0, k = 0;
        for(int cnt = 1; cnt < n; ++cnt){
            int cur = min(dp[i] * 2, min(dp[j] * 3, dp[k] * 5));
            if(cur == dp[i] * 2)
                ++i;
            if(cur == dp[j] * 3)
                ++j;
            if(cur == dp[k] * 5)
                ++k;
            dp[cnt] == cur;
        }
        return dp[n - 1];
    }
};