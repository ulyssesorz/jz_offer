class Solution {
public:
    int add(int a, int b) {
        while(b){
            int temp = a ^ b;   //不带进位的和
            b = (unsigned int)(a & b) << 1; //进位
            a = temp;
        }
        return a;
    }
};