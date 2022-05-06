class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        for(int i = 0; i < inorder.size(); ++i){
            map[inorder[i]] = i;    //建立中序遍历节点和索引的哈希
        }
        return build(0, 0, inorder.size() - 1);
    }
private:
    vector<int> preorder;
    unordered_map<int, int> map;
    TreeNode* build(int pre_root, int in_left, int in_right){
        if(in_left > in_right)
            return nullptr;     
        TreeNode* node = new TreeNode(preorder[pre_root]);
        int idx = map[preorder[pre_root]];  //前序首节点在中序节点的位置
        //左子树的根节点就是左子树前序的第一个节点，加1即可。左边界不变，右边界不能超过idx
        node->left = build(pre_root + 1, in_left, idx - 1); 
        //右子树的根节点就是右子树的前序的第一个节点，也就是当前根节点加上左子树的节点数目后加1
        //左子树的节点数目等于idx - in_left，左边界在idx右边，右边界不变
        node->right = build(pre_root + idx - in_left + 1, idx + 1, in_right);
        return node;
    }
};