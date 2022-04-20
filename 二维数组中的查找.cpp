class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty())   
            return false;
        int i_max=matrix.size()-1,j_max=matrix[0].size()-1; //行和列的最大值
        int i=0,j=j_max;
        while(i<=i_max && j<=j_max && i>=0 && j>=0)
        {
            if(matrix[i][j]==target)
                return true;
            if(matrix[i][j]>target) //列指针向左移动
                j--;
            else                   //行指针向下移动
                i++;    
        } 
        return false;
    }
};