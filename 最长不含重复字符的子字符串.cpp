class Solution {    //��ϣ����
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int right=0,res=0;
        for(int i=0;i<s.size();++i){
            if(i!=0)
                set.erase(s[i-1]);  //������ָ��
            while(right<s.size() && !set.count(s[right])){
                set.insert(s[right]);    //��ָ�����
                ++right;
            }
        res=max(res,right-i);
        }
        return res;
    }
};