class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m,vector<bool>(n,0));
        return dfs(0,0,m,n,k,visited);
    }
private:
    int dfs(int i, int j, int m, int n, int k, vector<vector<bool>>& visited){
        if(i>=m || j>=n || visited[i][j]==1 || sum(i,j)>k)  //�����ϰ�
            return 0;
        visited[i][j]=1;    //���Ϊ�ѷ���
        return 1+dfs(i+1,j,m,n,k,visited)+dfs(i,j+1,m,n,k,visited); //����������
    }
    int sum(int x, int y){  //������������λ��֮��
        int res;
        while(x){
            res+=x%10;
            x/=10;
        }
        while(y){
            res+=y%10;
            y/=10;
        }
        return res;
    }
};