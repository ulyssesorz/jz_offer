class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        vector<int> vec(32);
        for(int n : nums){
            for(int i = 31; i >= 0; --i){   //ͳ��ÿһλ��0�ĸ���
                vec[i] += n & 1;    
                n >>= 1;
            }
        }
        for(int i = 0; i < 32; ++i){
            if(vec[i] % 3 != 0)         //����3����˵����һλ��Ψһ���Ǹ�����λ
                res += pow(2, 31 - i);
        }
        return res;
    }
};