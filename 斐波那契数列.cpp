class Solution {
public:
    int fib(int n) {
        if(n==0)
            return 0;   //�ų�0���������
        int i=0,j=1;
        int temp;
        while(--n){
            temp=j;
            j=(i+j)%1000000007; 
            i=temp;     //��󻬶�
        }
        return j;
    }
};