class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty() || matrix[0].empty())
            return res;
        int left = 0, right = matrix[0].size() - 1; //左右边界
        int up = 0, down = matrix.size() - 1;   //上下边界
        while(1){
            for(int i = left; i <= right; ++i)//向右
                res.push_back(matrix[up][i]);   
            if(++up > down) //压缩边界并检查是否已没有元素
                break;
            for(int i = up; i <= down; ++i)//向下    
                res.push_back(matrix[i][right]);
            if(--right < left)
                break;
            for(int i = right; i >= left; --i)//向左
                res.push_back(matrix[down][i]);
            if(--down < up)
                break;
            for(int i = down; i >= up; --i)//向上
                res.push_back(matrix[i][left]);
            if(++left > right)
                break;
        }
        return res;
    }
};
// 1 2  3  4
// 5 6  7  8
// 9 10 11 12

// 1 2 3
// 4 5 6
// 7 8 9