class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> match(m + 1, vector<bool>(n + 1));
        for(int i = 0;i <= m; ++i){
            for(int j = 0; j <= n; ++j){
                if(j == 0){ //p为空
                    if(i == 0)  //s也为空，匹配
                        match[i][j] = 1;
                    else        //s非空，不匹配
                        match[i][j] = 0;
                }
                else{
                    if(p[j - 1] != '*'){    //p不是*
                        if(i > 0 && s[i - 1] == p[j - 1] || p[j - 1] == '.')
                            match[i][j] = match[i - 1][j - 1];  //之前匹配，加上当前字符也匹配
                    }
                    else{   //p是*
                        //不看p后两位
                        if(j > 1)   
                            match[i][j] = match[i][j - 2];
                        //p的*前一位能和s匹配上，s前移一位
                        if(i > 0 && j > 1 && s[i - 1] == p[j - 2] || p[j - 2] == '.')
                            match[i][j] = match[i - 1][j];
                    }
                }   
            }
        }
        return match[m][n];
    }
};