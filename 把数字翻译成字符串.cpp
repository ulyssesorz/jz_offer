class Solution {  //��̬�滮
public:
    int translateNum(int num) {
        string str=to_string(num);
        int i=1,j=1,temp;
        for(int k=2;k<=str.size();++k){
            if(str.substr(k-2,2)>="10" && str.substr(k-2,2)<="25")
                temp=i+j;   //�������������
            else
                temp=j;
            i=j;
            j=temp;
        }
        return j;
    }
};

class Solution { //�ݹ�
public:
    int translateNum(int num) {
        if(num<10)
            return 1;
        int m=num%100;  //ȡ��λ��
        if(m>=10 && m<=25)
            return translateNum(num/10)+translateNum(num/100);  //�ܷ�����λ
        else
            return translateNum(num/10);    //ֻ�ܷ���һλ
    }
};