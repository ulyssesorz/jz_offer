class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int len=nums.size();
        int i=0,j=len-1;
        while(i<=j){
            if(nums[i]%2==0 && nums[j]%2==1){   //�����ż�����ұ�������������
                swap(nums[i],nums[j]);
                ++i;--j;
                continue;
            }
            if(nums[i]%2==1)    //ֻ����߲����㽻������
                ++i;
            if(nums[j]%2==0)    //ֻ���ұ߲����㽻������
                --j;      
        }
        return nums;
    }
};