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
        target-=root->val;          //先加入当前节点，并计算剩余需要的数
        if(root->left==nullptr && root->right==nullptr && target==0)
            res.push_back(path);    //得到一条符合题意的路径
        dfs(root->left,target);
        dfs(root->right,target);
        path.pop_back();            //回溯，删除当前节点
    }
};