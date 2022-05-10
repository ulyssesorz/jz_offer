class Solution {
public:
    bool isNumber(string s) {
        if(s.empty())
            return false;
        int i = 0;
        //去除空格
        while(s[i] == ' ')
            ++i;
        //判断.和e前面是否是整数
        bool num = isInteger(s, i);
        //遇到. 后接无符号数
        if(s[i] == '.'){
            ++i;
            num = isUnsignedInt(s, i) || num;
        }
        //遇到e 后接整数
        if(s[i] == 'e' || s[i] == 'E'){
            ++i;
            num = isInteger(s, i) && num;
        }
        //是否出现其他异常符号
        while(s[i] == ' ')
            ++i;
        return num && i == s.size();
    }
private:
    bool isInteger(string s, int& idx){
        if(s[idx] == '+' || s[idx] == '-')
            ++idx;
        return isUnsignedInt(s, idx);
    }
    bool isUnsignedInt(string s, int& idx){
        int tmp = idx;
        while(idx != s.size() && s[idx] >= '0' && s[idx] <= '9')
            ++idx;
        return idx > tmp;
    }
};