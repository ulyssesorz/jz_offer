class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root==nullptr)
            return nullptr;
        dfs(root);
        head->left=pre; //修改首尾节点形成循环
        pre->right=head;
        return head;
    }
private:
    Node *head,*pre;       //head存储第一个节点，pre指向前一个节点
    void dfs(Node* root){
        if(root==nullptr)
            return;
        dfs(root->left);
        if(pre==nullptr)    //root是第一个节点，没有pre
            head=root;
        else
            pre->right=root;
        root->left=pre;     //前后节点的链接
        pre=root;           //pre向后移动
        dfs(root->right);
    }
};