class Solution {
public:
    int add(int a, int b) {
        while(b){
            int temp = a ^ b;   //������λ�ĺ�
            b = (unsigned int)(a & b) << 1; //��λ
            a = temp;
        }
        return a;
    }
};