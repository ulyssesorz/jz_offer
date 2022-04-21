class Solution {
public:
    int minArray(vector<int>& numbers) {
        int l=0,r=numbers.size()-1;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(numbers[m]>numbers[r])   //numbers[m]һ��������Сֵ
                l=m+1;
            else if(numbers[m]<numbers[r])  //numbers[m]��������Сֵ
                r=m;
            else
                --r;
        }
        return numbers[l];
    }
};