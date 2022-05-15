class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1;  //初始一位数
        long count = 9;  //初始0~9共9个数
        long start = 1;  //从1开始
        while(n > count){
            n -= count;
            ++digit;    //每次增加一位
            start *= 10;    //分别从1、10、100...开始
            count = start * digit * 9;  //数字总数分别是9、90、900...即1-9、10-99
        }
        --n;    
        int num = start + n / digit; //得到需要的数字
        int res = int(to_string(num)[n % digit] - '0'); //确定是哪一位
        return res;
    }
};