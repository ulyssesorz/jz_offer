class Solution {
public:
    int lastRemaining(int n, int m) {
        int res = 0;
        for(int i = 2; i <= n ; ++i){
            res = (res + m) % i;
        }
        return res;
    }
private:
    //f(n,m) = (m+f(n-1,m))%n
    int func(int n, int m){
        if(n == 1)
            return 0;
        return (m + func(n - 1, m)) % n;
    }
};