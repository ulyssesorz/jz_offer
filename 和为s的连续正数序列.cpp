class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int i = 1, j = 1;
        int sum = 0;
        while(i <= target / 2){
            if(sum < target){   //未满足target大小，右端点向后滑动
                sum += j;
                ++j;
            }
            else if(sum > target){  //超过target，说明该i端点出发无结果，改为下一个左端点i+1
                sum -= i;
                ++i;
            }
            else{   //找到序列，加入res中，并从下一个左端点出发
                vector<int> tmp;
                for(int k = i; k < j; ++k)
                    tmp.push_back(k);
                res.push_back(tmp);
                sum -= i;
                ++i;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        for(int i = 1; i <= target - 1; ++i){
            int sum = 0;
            vector<int> temp;
            for(int j = i; j <= target - 1; ++j){
                sum += j;
                temp.push_back(j);
                if(sum == target){
                    res.push_back(temp);
                    break;
                }
                if(sum > target)
                    break;
            }
        }
        return res;
    }
};