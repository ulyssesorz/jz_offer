class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        long digit = 1;
        int low = 0;    //cur从个位开始，此时没有low
        int high = n / 10;  //最高位
        int cur = n % 10;   //初始为最低位
        while(high != 0 || cur != 0){
            if(cur == 0)
                res += high * digit ;
            else if(cur == 1)
                res += high * digit + low + 1;
            else
                res += high * digit + digit;
            low += cur * digit;
            cur = high % 10;
            high /= 10;
            digit *= 10;
        }
        return res;
    }
};