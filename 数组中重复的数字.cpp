class Solution  //哈希表
{
public:
    int findRepeatNumber(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> res(n);
        for(int i=0;i<n;i++)
        {
            if(res[nums[i]]==0)
                res[nums[i]]=1;
            else
                return nums[i];
        }
        return -1;
    }
};
class Solution  //字典
{
public:
    int findRepeatNumber(vector<int>& nums) 
    {
        int i=0;
        while(i<nums.size())
        {
            if(nums[i]==i)  //值和索引的映射已建立
                ++i;
            else
            {
                if(nums[nums[i]]==nums[i])  //建立映射时出现重复，得到结果
                    return nums[i];
                swap(nums[nums[i]],nums[i]);    //交换后再找新的映射
            }
        }
        return -1;
    }       
};