class Solution {
public:
    bool isNumber(string s) {
        if(s.empty())
            return false;
        int i = 0;
        //ȥ���ո�
        while(s[i] == ' ')
            ++i;
        //�ж�.��eǰ���Ƿ�������
        bool num = isInteger(s, i);
        //����. ����޷�����
        if(s[i] == '.'){
            ++i;
            num = isUnsignedInt(s, i) || num;
        }
        //����e �������
        if(s[i] == 'e' || s[i] == 'E'){
            ++i;
            num = isInteger(s, i) && num;
        }
        //�Ƿ���������쳣����
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