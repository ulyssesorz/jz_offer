class Solution {
public:
    vector<int> printNumbers(int n) {
        for(int i = 1; i <= n; ++i){
            perm(0, i);
        }
        vector<int> true_vec;
        for(int i = 0; i < res.size(); ++i){
            true_vec.push_back(stoi(res[i]));
        }
        return true_vec;
    }
private:
    vector<string> res;
    string cur;
    const char nums[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    void perm(int x, int len){  //cur长度足够，加到结果res中
        if(x == len){
            res.push_back(cur);
            return;
        }
        int start = x == 0 ? 1 : 0; //个位数从1开始，避免0开头
        for(int i = start; i <= 9; ++i){   
            cur.push_back(nums[i]); 
            perm(x + 1, len);
            cur.pop_back();
        } 
    }
};