class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(lrGap(root) == -1)
            return false;
        return true;
    }
private:
    int lrGap(TreeNode* root){
        if(root == nullptr) 
            return 0;
        int left = lrGap(root->left);
        if(left == -1)
            return -1;  //非平衡，剪枝
        int right = lrGap(root->right);
        if(right == -1)
            return -1;
        if(abs(left - right) > 1)
            return -1;
        else
            return max(left, right) + 1;   //平衡，向下求深度
    }
};