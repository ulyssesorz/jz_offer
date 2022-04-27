class Solution {
public:
    string reverseWords(string s) {
        string res="";
        for(int i=s.size()-1;i>=0;--i){
            if(s[i]!=' '){
                int j=i;
                while(i>=0 && s[i]!=' ')
                    --i;
                res+=s.substr(i+1,j-i)+" ";
            }
        }
        return res.substr(0,res.size()-1);
    }
};