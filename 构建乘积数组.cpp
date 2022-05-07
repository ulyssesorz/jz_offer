class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if(a.empty())
            return {};
        vector<int> b(a.size());
        b[0] = 1;
        for(int i = 1; i < a.size(); ++i){  //i���Ԫ�س˻�
            b[i] = b[i - 1] * a[i - 1]; 
        }
        int temp = 1;
        for(int i = a.size() - 1; i >= 0; --i){ 
            b[i] *= temp;   //���Ҳ�ĳ˻�
            temp *= a[i];   //i�Ҳ�Ԫ�صĳ˻�
        }
        return b;
    }
};
