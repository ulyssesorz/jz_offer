class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> str;
        string res;
        for(int n:nums){
            str.push_back(to_string(n));
        }
        sort(str.begin(),str.end(),cmp);
        //quicksort(str,0,str.size()-1);
        for(string s:str){
            res+=s;
        }
        return res;
    }
private:
    static bool cmp(string a, string b){
        return a+b<b+a; 
    }
    void quicksort(vector<string>& str, int low, int high){
        if(low>=high)
            return;
        int i=low,j=high;
        while(i<j){
            while(i<j && str[j]+str[low]>=str[low]+str[j])
                --j;
            while(i<j && str[i]+str[low]<=str[low]+str[i])
                ++i;
            swap(str[i],str[j]);
        }
        swap(str[i],str[low]);
        quicksort(str,low,i-1);
        quicksort(str,i+1,high);
    }
};
