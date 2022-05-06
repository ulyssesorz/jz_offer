class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0)
            return 0;
        long N = n; //防溢出
        double res = 1;
        if(N < 0){
            x = 1 / x;
            N = -N;
        }
        while(N > 0){
            if(N & 1 == 1)  
                res *= x;
            x *= x;     //x的2幂次方（x^2,x^4,x^8...）
            N >>= 1;    //后移一位
        }
        return res;
    }
};