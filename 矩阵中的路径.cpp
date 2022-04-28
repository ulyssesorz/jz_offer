class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty())
            return false;
        M=board.size();
        N=board[0].size();
        bool res;
        for(int i=0;i<M;++i){
            for(int j=0;j<N;++j){
                if(dfs(board,word,i,j,0))   //分别以每个网格为起点开始查找
                    return true;
            }
        }
        return false;
    }
private:
    int M,N;
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k){
        if(i>=M || i<0 || j>=N || j<0 || board[i][j]!=word[k])  //剪枝的几种情况
            return false;
        if(k==word.size()-1)    //最后一个字符查找成功
            return true;
        board[i][j]='\0';   //标记为已访问
        bool res=dfs(board,word,i+1,j,k+1) || dfs(board,word,i,j+1,k+1) || dfs(board,word,i-1,j,k+1) || dfs(board,word,i,j-1,k+1);
        //上下左右四个方向查找
        board[i][j]=word[k];    //还原，避免影响下一趟查找
        return res; 
    }
};