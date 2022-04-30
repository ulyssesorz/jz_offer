class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int cnt=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;++i){
            if(nums[i]==0){ //统计0的数目
                ++cnt;
                continue;
            }
            else if(nums[i]==nums[i+1]) //有重复元素直接判负
                return false;
            int gap=nums[i+1]-nums[i]-1;    //计算需要填补的空隙
            cnt-=gap;
        }
        if(cnt>=0)      //足够填补
            return true;
        return false;
    }
};