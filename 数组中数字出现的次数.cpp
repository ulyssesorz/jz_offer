class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int sum = 0;
        for(int n : nums)
            sum ^= n;
        int flag = 1;
        while((sum & flag) == 0)    //找到不同的那一位
            flag <<= 1;
        int res1 = 0, res2 = 0;
        for(int n :nums){   //分组，组内异或得到出现次数为1的那个数
            if(n & flag)
                res1 ^= n;
            else
                res2 ^= n;
        }
        return {res1, res2};
    }
};