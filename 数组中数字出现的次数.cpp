class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int sum = 0;
        for(int n : nums)
            sum ^= n;
        int idx = 0;
        while((sum & 1) == 0){  //��ͬ��λ
            ++idx;
            sum >>= 1;
        }
        int res1 = 0, res2 = 0;
        for(int n :nums){
            if((n >> idx & 1) == 1) //���飬�������
                res1 ^= n;
            else
                res2 ^= n;
        }
        return {res1, res2};
    }
};