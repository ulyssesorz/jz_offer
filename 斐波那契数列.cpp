class Solution {
public:
    int fib(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;   //前两项0,1的结果
        int i=0,j=1;
        int temp;
        for(int k=2;k<=n;k++){      //后n-2项的结果
            temp=j;
            j=(i+j)%1000000007;
            i=temp;
        }
        return j;
    }
};