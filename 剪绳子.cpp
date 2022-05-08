class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for(int i = 3; i < n + 1; ++i){ //n�������г������ӵ����
            for(int j = 1; j < i - 1; ++j){ //��ѡ����ĳ���
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));    
            }
        }
        return dp[n];
    }
};