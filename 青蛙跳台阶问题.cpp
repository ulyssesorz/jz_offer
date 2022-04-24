class Solution {
public:
    int numWays(int n) {
        if(n==0 || n==1)
            return 1;       //前两项
        int i=1,j=1;
        int temp;
        for(int k=2;k<=n;k++){   //后n-2项
            temp=j;
            j=(i+j)%1000000007;
            i=temp;
        }
        return j;
    }
};