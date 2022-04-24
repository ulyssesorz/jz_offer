class Solution {    //动态规划
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int min_price=prices[0],max_profit=0;
        for(int i=1;i<prices.size();++i){
            min_price=min(min_price,prices[i]);     //更新当前最低价格
            max_profit=max(max_profit,prices[i]-min_price);     //更新当前最大利润
        }
        return max_profit;
    }
};