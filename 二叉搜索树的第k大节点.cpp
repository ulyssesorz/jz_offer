class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        count=k;
        inorder(root);
        return res;
    }
private:
    int res,count;
    void inorder(TreeNode* root){
        if(root==nullptr)
            return;
        inorder(root->right);   //����������������
        if(--count==0){
            res=root->val;      //�ҵ���k��Ľڵ㣬������res��
            return;
        }
        inorder(root->left);
    }
};