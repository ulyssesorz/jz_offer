class Solution {
public:
    vector<double> dicesProbability(int n) {
        int dp[n + 1][n * 6 + 1];   //Ͷ����iö���Ӻ󣬵���j�ĳ��ִ���
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= 6; ++i){
            dp[1][i] = 1;
        }
        for(int i = 2; i <= n; ++i){    //Ͷ��i������
            for(int j = i; j <= i * 6; ++j){     //i�����ӿ��ܵĵ�����
                for(int k = 1; k <= 6; ++k){    //��ǰ���ӵĵ���
                    if(j - k <= 0)
                        break;
                    dp[i][j] += dp[i - 1][j - k]; 
                }
            }
        }
        vector<double> res;
        double sum = pow(6.0, n);
        for(int i = n; i <= 6 * n; ++i){    //�����
            res.push_back(dp[n][i] * 1.0 / sum);
        }
        return res;
    }
};