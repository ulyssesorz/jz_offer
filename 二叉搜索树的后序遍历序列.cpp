class Solution {    //单调栈
public:
    bool verifyPostorder(vector<int>& postorder) {
        stack<int> stack;
        int root = INT_MAX;
        for(int i = postorder.size() - 1; i >= 0; --i){  
            while(!stack.empty() && stack.top() > postorder[i]){
                root = stack.top();     //找父节点
                stack.pop();
            }
            if(postorder[i] > root) //左节点大于根节点
                return false; 
            stack.push(postorder[i]);
        }
        return true;
    }
};

class Solution {    //递归
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
        while(postorder[mid] < postorder[right])    //找第一个大于根节点的值，即右子树的根节点
            ++mid;
        int temp = mid;
        while(postorder[temp] > postorder[right])   //判断右子树是否满足BFS
            ++temp;
        return temp == right && split(postorder, left, mid - 1) && split(postorder, mid, right - 1);
    }
};