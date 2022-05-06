class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0)
            return 0;
        long N = n; //�����
        double res = 1;
        if(N < 0){
            x = 1 / x;
            N = -N;
        }
        while(N > 0){
            if(N & 1 == 1)  
                res *= x;
            x *= x;     //x��2�ݴη���x^2,x^4,x^8...��
            N >>= 1;    //����һλ
        }
        return res;
    }
};