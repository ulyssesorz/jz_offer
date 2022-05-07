class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        vector<int> vec(32);
        for(int n : nums){
            for(int i = 31; i >= 0; --i){   //统计每一位非0的个数
                vec[i] += n & 1;    
                n >>= 1;
            }
        }
        for(int i = 0; i < 32; ++i){
            if(vec[i] % 3 != 0)         //不被3整除说明这一位是唯一的那个数的位
                res += pow(2, 31 - i);
        }
        return res;
    }
};