class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if(root!=nullptr)
            q.push(root); 
        while(!q.empty())
        {
            TreeNode* cur=q.front();
            q.pop();
            res.push_back(cur->val);
            if(cur->left!=nullptr)
                q.push(cur->left);
            if(cur->right!=nullptr)
                q.push(cur->right);
        }
        return res;
    }
};