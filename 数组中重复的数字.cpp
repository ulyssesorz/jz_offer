class Solution  //��ϣ��
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
class Solution  //�ֵ�
{
public:
    int findRepeatNumber(vector<int>& nums) 
    {
        int i=0;
        while(i<nums.size())
        {
            if(nums[i]==i)  //ֵ��������ӳ���ѽ���
                ++i;
            else
            {
                if(nums[nums[i]]==nums[i])  //����ӳ��ʱ�����ظ����õ����
                    return nums[i];
                swap(nums[nums[i]],nums[i]);    //�����������µ�ӳ��
            }
        }
        return -1;
    }       
};