class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int cnt=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;++i){
            if(nums[i]==0){ //ͳ��0����Ŀ
                ++cnt;
                continue;
            }
            else if(nums[i]==nums[i+1]) //���ظ�Ԫ��ֱ���и�
                return false;
            int gap=nums[i+1]-nums[i]-1;    //������Ҫ��Ŀ�϶
            cnt-=gap;
        }
        if(cnt>=0)      //�㹻�
            return true;
        return false;
    }
};