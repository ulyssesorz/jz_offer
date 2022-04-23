class Solution {
public:
    int fib(int n) {
        if(n==0)
            return 0;   //排除0的特殊情况
        int i=0,j=1;
        int temp;
        while(--n){
            temp=j;
            j=(i+j)%1000000007; 
            i=temp;     //向后滑动
        }
        return j;
    }
};