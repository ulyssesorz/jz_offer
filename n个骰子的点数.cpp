class Solution {
public:
    vector<double> dicesProbability(int n) {
        int dp[n + 1][n * 6 + 1];   //投掷完i枚骰子后，点数j的出现次数
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= 6; ++i){
            dp[1][i] = 1;
        }
        for(int i = 2; i <= n; ++i){    //投第i个骰子
            for(int j = i; j <= i * 6; ++j){     //i个骰子可能的点数和
                for(int k = 1; k <= 6; ++k){    //当前骰子的点数
                    if(j - k <= 0)
                        break;
                    dp[i][j] += dp[i - 1][j - k]; 
                }
            }
        }
        vector<double> res;
        double sum = pow(6.0, n);
        for(int i = n; i <= 6 * n; ++i){    //求概率
            res.push_back(dp[n][i] * 1.0 / sum);
        }
        return res;
    }
};