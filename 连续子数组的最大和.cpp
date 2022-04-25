class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur=nums[0];
        int max_res=cur;
        for(int i=1;i<nums.size();++i){
            cur=max(cur+nums[i],nums[i]);   //判断是否重新开始
            max_res=max(max_res,cur);
        }
        return max_res;
    }
};