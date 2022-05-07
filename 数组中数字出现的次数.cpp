class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int sum = 0;
        for(int n : nums)
            sum ^= n;
        int flag = 1;
        while((sum & flag) == 0)    //�ҵ���ͬ����һλ
            flag <<= 1;
        int res1 = 0, res2 = 0;
        for(int n :nums){   //���飬�������õ����ִ���Ϊ1���Ǹ���
            if(n & flag)
                res1 ^= n;
            else
                res2 ^= n;
        }
        return {res1, res2};
    }
};