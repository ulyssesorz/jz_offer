class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        int m;
        while(l<=r)
        {
            m=(l+r)/2;
            if(nums[m]>m)
                r=m-1;
            else
                l=m+1;
        }
        return l;
    }
};//0,2,3,4  //0,1,2,4
