class Solution {    //����
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k<=0)
            return {};
        vector<int> res(k);
        for(int i=0;i<k;++i){
            res[i]=arr[i];          //����k��Ԫ��
        }
        for(int i=k/2-1;i>=0;--i){  
            heapAdjust(res,k,i);    //����Ϊ�����
        }
        for(int i=k;i<arr.size();++i){
            if(arr[i]<res[0]){
                swap(arr[i],res[0]);    //�����С��������������
                heapAdjust(res,k,0);
            }
        }
        return res;       
    }
    void heapAdjust(vector<int>& arr, int len, int idx){//����Ϊ�����
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

class Solution {    //����
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
        if(i>k) //��k+1��Ԫ������ߵ�������
            quickSort(arr,low,i-1,k);   
        if(i<k) //��k+1��Ԫ�����ұߵ�������
            quickSort(arr,i+1,high,k);
        res.assign(arr.begin(), arr.begin() + k);
        return res;
    }
};