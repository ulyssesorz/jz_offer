class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m,vector<bool>(n,0));
        return dfs(0,0,m,n,k,visited);
    }
private:
    int dfs(int i, int j, int m, int n, int k, vector<vector<bool>>& visited){
        if(i>=m || j>=n || visited[i][j]==1 || sum(i,j)>k)  //遇到障碍
            return 0;
        visited[i][j]=1;    //标记为已访问
        return 1+dfs(i+1,j,m,n,k,visited)+dfs(i,j+1,m,n,k,visited); //继续向后查找
    }
    int sum(int x, int y){  //计算两个数的位数之和
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