class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        for(int i = 0; i < inorder.size(); ++i){
            map[inorder[i]] = i;    //������������ڵ�������Ĺ�ϣ
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
        int idx = map[preorder[pre_root]];  //ǰ���׽ڵ�������ڵ��λ��
        //�������ĸ��ڵ����������ǰ��ĵ�һ���ڵ㣬��1���ɡ���߽粻�䣬�ұ߽粻�ܳ���idx
        node->left = build(pre_root + 1, in_left, idx - 1); 
        //�������ĸ��ڵ������������ǰ��ĵ�һ���ڵ㣬Ҳ���ǵ�ǰ���ڵ�����������Ľڵ���Ŀ���1
        //�������Ľڵ���Ŀ����idx - in_left����߽���idx�ұߣ��ұ߽粻��
        node->right = build(pre_root + idx - in_left + 1, idx + 1, in_right);
        return node;
    }
};