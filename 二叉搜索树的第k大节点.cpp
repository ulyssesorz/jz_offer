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
        inorder(root->right);   //从右向左的中序遍历
        if(--count==0){
            res=root->val;      //找到第k大的节点，储存在res中
            return;
        }
        inorder(root->left);
    }
};