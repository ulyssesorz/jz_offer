class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int M=grid.size(),N=grid[0].size();
        int max_val=0;
        for(int i=0;i<M;++i){
            for(int j=0;j<N;++j){
                if(i==0 && j==0)
                    grid[i][j]=grid[i][j];  //起点没有上一步
                else if(i==0)
                    grid[i][j]=grid[i][j]+grid[i][j-1];    
                else if(j==0)
                    grid[i][j]=grid[i][j]+grid[i-1][j];
                else
                    grid[i][j]=grid[i][j]+max(grid[i-1][j],grid[i][j-1]); 
            }
        }
        return grid[M-1][N-1];
    }
};