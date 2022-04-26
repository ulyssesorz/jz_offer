class Solution {  //动态规划
public:
    int translateNum(int num) {
        string str=to_string(num);
        int i=1,j=1,temp;
        for(int k=2;k<=str.size();++k){
            if(str.substr(k-2,2)>="10" && str.substr(k-2,2)<="25")
                temp=i+j;   //满足条件则滚动
            else
                temp=j;
            i=j;
            j=temp;
        }
        return j;
    }
};

class Solution { //递归
public:
    int translateNum(int num) {
        if(num<10)
            return 1;
        int m=num%100;  //取两位数
        if(m>=10 && m<=25)
            return translateNum(num/10)+translateNum(num/100);  //能翻译两位
        else
            return translateNum(num/10);    //只能翻译一位
    }
};