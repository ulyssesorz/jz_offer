class Solution {    //堆排
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k<=0)
            return {};
        vector<int> res(k);
        for(int i=0;i<k;++i){
            res[i]=arr[i];          //读入k个元素
        }
        for(int i=k/2-1;i>=0;--i){  
            heapAdjust(res,k,i);    //调整为大根堆
        }
        for(int i=k;i<arr.size();++i){
            if(arr[i]<res[0]){
                swap(arr[i],res[0]);    //读入更小的数，并调整堆
                heapAdjust(res,k,0);
            }
        }
        return res;       
    }
    void heapAdjust(vector<int>& arr, int len, int idx){//调整为大根堆
        if(idx>=len)
            return;
        int max=idx;
        int left=idx*2+1;
        int right=idx*2+2;
        if(left<len && arr[left]>arr[max])
            max=left;
        if(right<len && arr[right]>arr[max])
            max=right;
        if(idx!=max){
            swap(arr[idx],arr[max]);
            heapAdjust(arr,len,max);
        }
    }
};

class Solution {    //快排
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k<=0)
            return {};
        if(k>=arr.size())
            return arr;
        return quickSort(arr,0,arr.size()-1,k);
    }
private:
    vector<int> res;
    vector<int> quickSort(vector<int>& arr, int low, int high, int k){
        int i=low,j=high;
        while(i<j){
            while(i<j && arr[j]>=arr[low])
                --j;
            while(i<j && arr[i]<=arr[low])
                ++i;
            swap(arr[i],arr[j]);
        }
        swap(arr[i],arr[low]);
        if(i>k) //第k+1个元素在左边的数列里
            quickSort(arr,low,i-1,k);   
        if(i<k) //第k+1个元素在右边的数列里
            quickSort(arr,i+1,high,k);
        res.assign(arr.begin(), arr.begin() + k);
        return res;
    }
};