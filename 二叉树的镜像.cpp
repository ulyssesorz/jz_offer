class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root==nullptr)
            return nullptr;
        TreeNode* temp=root->right; //�������ҽڵ�
        root->right=root->left;
        root->left=temp;
        mirrorTree(root->left);     //���µݹ鷴ת
        mirrorTree(root->right);
        return root;
    }
};