class Solution {    //��������
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.empty())
            return res;
        deque<int> dq;
        int i = 1 - k, j = 0;
        while(j < nums.size()){
            if(i > 0 && dq[0] == nums[i - 1])   //ɾ�����ڴ��ڵ����Ԫ��
                dq.pop_front();
            while(!dq.empty() && dq[dq.size() - 1] < nums[j])   //���ֶ��е�����
                dq.pop_back();
            dq.push_back(nums[j]);  
1
            ++i;
            ++j;
        }
        return res;
    }
};

class Solution {    //��������
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.empty())
            return res;
        int i = 0;
        while(i + k - 1 < nums.size()){
            int max = INT_MIN;
            for(int j = i; j <= i + k - 1; ++j){
                if(nums[j] >= max)
                    max = nums[j];
            }
            res.push_back(max);
            ++i;
        }
        return res;
    }
};