class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left,right,m;
        int i=0,j=nums.size()-1;
        while(i<=j) //ÕÒÓÒ¶Ë±ß½ç
        {
            m=(i+j)/2;
            if(nums[m]<=target)
                i=m+1;
            else
                j=m-1;
        }
        right=i;
        i=0;j=nums.size()-1;
        while(i<=j) //ÕÒ×ó¶Ë±ß½ç
        {
            m=(i+j)/2;
            if(nums[m]>=target)
                j=m-1;
            else 
                i=m+1;
        }
        left=j;
        return right-left-1;
    }
};