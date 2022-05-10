class Solution {    //1
public:
    int strToInt(string str) {
        if(str.empty())
            return 0;
        int i = 0;
        //去除空格
        while(str[i] == ' ')
            ++i;
        //判断符号
        bool flag = 0;
        if(str[i] == '-'){
            flag = 1;
            ++i;
        }
        else if(str[i] == '+'){
            ++i;
        }
        else if(str[i] < '0' || str[i] > '9')
            return 0;
        //转化为数字
        if(i == str.size())
            return 0;
        double res = 0;
        while(str[i] >= '0' && str[i] <= '9'){
            if(flag)
                res = res * 10 - (str[i] - '0');
            else
                res = res * 10 + (str[i] - '0');
            ++i;
            if(res > INT_MAX)
                return INT_MAX;
            if(res < INT_MIN)
                return INT_MIN;
        }
        return res;
    }
};

class Solution {    //2
public:
    int strToInt(string str) {
        if(str.empty())
            return 0;
        int i = 0;
        string num;
        //去除空格
        while(str[i] == ' ')
            ++i;
        //判断符号
        bool flag = 0;
        if(str[i] >= '0' && str[i] <= '9'){;}
        else if(str[i] == '-'){
            flag = 1;
            ++i;
        }
        else if(str[i] == '+'){
            ++i;
        }
        else
            return 0;
        //读入数字
        while(str[i] >= '0' && str[i] <= '9'){
            num += str[i];
            ++i;
        }
        //转化为数字
        if(num.empty())
            return 0;
        double res = 0;
        double k = 1;
        for(int j = num.size() - 1; j >= 0; --j){
            if(flag)
                res -= tanslate(num[j]) * k;
            else    
                res += tanslate(num[j]) * k;
            k *= 10;
            if(res > INT_MAX)
                return INT_MAX;
            if(res < INT_MIN)
                return INT_MIN;
        }
        return res;
    }
private:
    double tanslate(char c){
        switch(c){
            case '0': return 0;
            case '1': return 1;
            case '2': return 2;
            case '3': return 3;
            case '4': return 4;
            case '5': return 5;
            case '6': return 6;
            case '7': return 7;
            case '8': return 8;
            case '9': return 9;
        }
        return -1;
    }
};