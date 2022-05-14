class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size());
        for(int i = 0; i < nums.size(); ++i){
            tmp[i] = nums[i];
        }
        return mergeSort(nums, tmp, 0, nums.size() - 1);
    }
private:
    int mergeSort(vector<int>& nums, vector<int>& tmp, int low, int high){
        if(low >= high)
            return 0;
        int mid = low + (high - low) / 2;
        int res = mergeSort(nums, tmp, low, mid) + mergeSort(nums, tmp, mid + 1, high);
        for(int i = 0; i < nums.size(); ++i){
            tmp[i] = nums[i];
        }
        int i = low, j = mid + 1, k = low;
        while(i <= mid && j <= high){
            if(tmp[i] <= tmp[j])
                nums[k++] = tmp[i++];
            else{
                nums[k++] = tmp[j++];
                res += mid - i + 1;
            }
        }
        while(i <= mid)
            nums[k++] = tmp[i++];
        while(j <= high)
            nums[k++] = tmp[j++];
        return res;
    }
};