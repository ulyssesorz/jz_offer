class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> match(m + 1, vector<bool>(n + 1));
        for(int i = 0;i <= m; ++i){
            for(int j = 0; j <= n; ++j){
                if(j == 0){ //pΪ��
                    if(i == 0)  //sҲΪ�գ�ƥ��
                        match[i][j] = 1;
                    else        //s�ǿգ���ƥ��
                        match[i][j] = 0;
                }
                else{
                    if(p[j - 1] != '*'){    //p����*
                        if(i > 0 && s[i - 1] == p[j - 1] || p[j - 1] == '.')
                            match[i][j] = match[i - 1][j - 1];  //֮ǰƥ�䣬���ϵ�ǰ�ַ�Ҳƥ��
                    }
                    else{   //p��*
                        //����p����λ
                        if(j > 1)   
                            match[i][j] = match[i][j - 2];
                        //p��*ǰһλ�ܺ�sƥ���ϣ�sǰ��һλ
                        if(i > 0 && j > 1 && s[i - 1] == p[j - 2] || p[j - 2] == '.')
                            match[i][j] = match[i - 1][j];
                    }
                }   
            }
        }
        return match[m][n];
    }
};