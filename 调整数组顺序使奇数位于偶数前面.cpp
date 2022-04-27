class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int len=nums.size();
        int i=0,j=len-1;
        while(i<=j){
            if(nums[i]%2==0 && nums[j]%2==1){   //左边是偶数，右边是奇数，交换
                swap(nums[i],nums[j]);
                ++i;--j;
                continue;
            }
            if(nums[i]%2==1)    //只有左边不满足交换条件
                ++i;
            if(nums[j]%2==0)    //只有右边不满足交换条件
                --j;      
        }
        return nums;
    }
};