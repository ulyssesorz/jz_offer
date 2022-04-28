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
                if(dfs(board,word,i,j,0))   //�ֱ���ÿ������Ϊ��㿪ʼ����
                    return true;
            }
        }
        return false;
    }
private:
    int M,N;
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k){
        if(i>=M || i<0 || j>=N || j<0 || board[i][j]!=word[k])  //��֦�ļ������
            return false;
        if(k==word.size()-1)    //���һ���ַ����ҳɹ�
            return true;
        board[i][j]='\0';   //���Ϊ�ѷ���
        bool res=dfs(board,word,i+1,j,k+1) || dfs(board,word,i,j+1,k+1) || dfs(board,word,i-1,j,k+1) || dfs(board,word,i,j-1,k+1);
        //���������ĸ��������
        board[i][j]=word[k];    //��ԭ������Ӱ����һ�˲���
        return res; 
    }
};