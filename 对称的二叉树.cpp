class Solution {
public:
    bool isSame(TreeNode* A,TreeNode* B){
        if(A==nullptr && B==nullptr)
            return true;
        if(A==nullptr || B==nullptr)
            return false;
        return A->val==B->val && isSame(A->left,B->right) && isSame(A->right,B->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
            return true;
        return isSame(root->left,root->right);
    }
};