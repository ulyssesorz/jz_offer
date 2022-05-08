class Solution {    //公式推导
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

class Solution {    //模拟
public:
    int lastRemaining(int n, int m) {
        vector<int> circle(n);
        for(int i = 0; i < n; ++i){
            circle[i] = i;
        }
        int idx = 0;
        while(circle.size() > 1){
            idx = (idx + m -1) % circle.size();
            circle.erase(circle.begin() + idx);
        }
        return circle[0];
    }
};