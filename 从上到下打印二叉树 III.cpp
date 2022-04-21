class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector <int>> res;
        queue<TreeNode*> q;
        stack<int> s;
        int flag=1;
        if(root!=nullptr)
            q.push(root); 
        while(!q.empty()){
            int cur_size=q.size();
            res.push_back(vector<int> ());
            for(int i=0;i<cur_size;i++){
                TreeNode* cur=q.front();
                q.pop();
                if(flag%2==1){  //������
                    res.back().push_back(cur->val);
                    if(cur->left!=nullptr)
                        q.push(cur->left);
                    if(cur->right!=nullptr)
                        q.push(cur->right);
                }
                else{       //ż����
                    s.push(cur->val);       //����ջ�ݴ�
                    if(cur->left!=nullptr)
                        q.push(cur->left);
                    if(cur->right!=nullptr)
                        q.push(cur->right);
                }
            }
            if(flag%2==0){
                for(int i=0;i<cur_size;i++){
                    res.back().push_back(s.top());  //ջ��Ԫ�ص���������
                    s.pop();
                }
            }
            ++flag;
        }
        return res;
    }
};