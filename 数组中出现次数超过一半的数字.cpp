class Solution {    //Ħ��ͶƱ
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int cnt = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == major)
                ++cnt;
            else
                --cnt;
            if(cnt == 0){   //�л�major�����¼���
                cnt = 1;
                major = nums[i];
            }
        }
        return major;
    }
};

class Solution {    //��ϣ��
public:
    int majorityElement(vector<int>& nums) {
        int res;
        unordered_map<int, int> map;
        for(int n : nums){
            ++map[n];
        }
        for(auto it : map){
            if(it.second > nums.size() / 2)
                res =  it.first;
        }
        return res;
    }
};

class Solution {    //ȡ��λ��
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};