class Solution {    //��̬�滮
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int min_price=prices[0],max_profit=0;
        for(int i=1;i<prices.size();++i){
            min_price=min(min_price,prices[i]);     //���µ�ǰ��ͼ۸�
            max_profit=max(max_profit,prices[i]-min_price);     //���µ�ǰ�������
        }
        return max_profit;
    }
};