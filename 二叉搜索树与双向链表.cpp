class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root==nullptr)
            return nullptr;
        dfs(root);
        head->left=pre; //�޸���β�ڵ��γ�ѭ��
        pre->right=head;
        return head;
    }
private:
    Node *head,*pre;       //head�洢��һ���ڵ㣬preָ��ǰһ���ڵ�
    void dfs(Node* root){
        if(root==nullptr)
            return;
        dfs(root->left);
        if(pre==nullptr)    //root�ǵ�һ���ڵ㣬û��pre
            head=root;
        else
            pre->right=root;
        root->left=pre;     //ǰ��ڵ������
        pre=root;           //pre����ƶ�
        dfs(root->right);
    }
};