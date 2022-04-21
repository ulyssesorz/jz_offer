class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector <int>> res;
        queue<TreeNode*> q;
        if(root!=nullptr)
            q.push(root); 
        while(!q.empty())
        {
            int cur_size=q.size();          //��ǰ���г��ȣ���ͬһ��ڵ����
            res.push_back(vector<int> ());  //�����µĲ�
            for(int i=0;i<cur_size;i++)
            {
                TreeNode* cur=q.front();
                q.pop();
                res.back().push_back(cur->val);
                if(cur->left!=nullptr)
                    q.push(cur->left);
                if(cur->right!=nullptr)
                    q.push(cur->right);
            }
        }
        return res;
    }
};