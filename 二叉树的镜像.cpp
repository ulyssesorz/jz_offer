class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==nullptr)
            return nullptr;
        TreeNode* temp=root->right; //交换左右节点
        root->right=root->left;
        root->left=temp;
        mirrorTree(root->left);     //向下递归反转
        mirrorTree(root->right);
        return root;
    }
};