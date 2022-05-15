class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1;  //��ʼһλ��
        long count = 9;  //��ʼ0~9��9����
        long start = 1;  //��1��ʼ
        while(n > count){
            n -= count;
            ++digit;    //ÿ������һλ
            start *= 10;    //�ֱ��1��10��100...��ʼ
            count = start * digit * 9;  //���������ֱ���9��90��900...��1-9��10-99
        }
        --n;    
        int num = start + n / digit; //�õ���Ҫ������
        int res = int(to_string(num)[n % digit] - '0'); //ȷ������һλ
        return res;
    }
};