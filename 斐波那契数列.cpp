class Solution {
public:
    int fib(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;   //ǰ����0,1�Ľ��
        int i=0,j=1;
        int temp;
        for(int k=2;k<=n;k++){      //��n-2��Ľ��
            temp=j;
            j=(i+j)%1000000007;
            i=temp;
        }
        return j;
    }
};