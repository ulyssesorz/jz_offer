class Solution {    //����ջ
public:
    bool verifyPostorder(vector<int>& postorder) {
        stack<int> stack;
        int root = INT_MAX;
        for(int i = postorder.size() - 1; i >= 0; --i){  
            while(!stack.empty() && stack.top() > postorder[i]){
                root = stack.top();     //�Ҹ��ڵ�
                stack.pop();
            }
            if(postorder[i] > root) //��ڵ���ڸ��ڵ�
                return false; 
            stack.push(postorder[i]);
        }
        return true;
    }
};

class Solution {    //�ݹ�
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.empty())
            return true;
        return split(postorder, 0, postorder.size() - 1);
    }
private:
    bool split(vector<int> postorder, int left, int right){
        if(left >= right)
            return true;
        int mid = left;
        while(postorder[mid] < postorder[right])    //�ҵ�һ�����ڸ��ڵ��ֵ�����������ĸ��ڵ�
            ++mid;
        int temp = mid;
        while(postorder[temp] > postorder[right])   //�ж��������Ƿ�����BFS
            ++temp;
        return temp == right && split(postorder, left, mid - 1) && split(postorder, mid, right - 1);
    }
};