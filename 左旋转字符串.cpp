class Solution {
public:
    string reverseLeftWords(string s, int n) 
    {
        string left;
        for(int i=0;i<n;i++)
        {
            left.push_back(s[i]);   //�ݴ����ת���ַ���
        }
        s.erase(0,n);
        for(int j=0;j<n;j++)
        {
            s.push_back(left[j]);   //�ӵ�����
        }
        return s;
    }
};