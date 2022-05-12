class Solution {
public:
    vector<string> permutation(string s) {
        if(s.empty())
            return {""};
        my_per(s, 0, s.size() - 1);
        return res;
    }
    void my_per(string& s, int begin, int end){
        if(begin == end){
            res.push_back(s);
            return;
        }
        for(int i = begin; i <= end; ++i){  //ѡ��i��begin����
            bool flag = false;
            for(int j = begin; j < i; ++j){ //�ų��ظ�Ԫ��
                if(s[i] == s[j])
                    flag = true;
            }
            if(!flag){
                swap(s[i], s[begin]);
                my_per(s, begin + 1, end);
                swap(s[i], s[begin]);
            }
        }
    }
private:
    vector<string> res;
};