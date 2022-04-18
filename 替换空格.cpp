class Solution 
{
public:
    string replaceSpace(string s) 
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
                s=s.replace(s.find(" "),1,"%20");
        }
        return s;
    }
};