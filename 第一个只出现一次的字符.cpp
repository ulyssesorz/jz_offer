class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char,int> map;
        for(char ch:s)
        {
            ++map[ch];  //��ϣ���¼���ִ���
        }
        for(int i=0;i<s.size();++i)
        {
            if(map[s[i]]==1)
                return s[i];
        }
        return ' ';
    }
};