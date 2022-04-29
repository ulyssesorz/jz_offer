class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root,target);
        return res;
    }
private:
    vector<int> path;
    vector<vector<int>> res;
    void dfs(TreeNode* root, int target){
        if(root==nullptr)
            return;
        path.push_back(root->val);  
        target-=root->val;          //�ȼ��뵱ǰ�ڵ㣬������ʣ����Ҫ����
        if(root->left==nullptr && root->right==nullptr && target==0)
            res.push_back(path);    //�õ�һ�����������·��
        dfs(root->left,target);
        dfs(root->right,target);
        path.pop_back();            //���ݣ�ɾ����ǰ�ڵ�
    }
};