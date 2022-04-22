class Solution {
public:
    bool isSame(TreeNode* A, TreeNode* B){
        if(B==nullptr)      //B已经越过叶节点
            return true;
        if(A==nullptr)      //B不空但A为空
            return false;
        return (A->val==B->val) && isSame(A->left,B->left) && isSame(A->right,B->right);
        //结构相同的条件：当前值相等、左右子节点也相同    
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==nullptr || B==nullptr)    //排除其中一方为空树的可能
            return false;
        return isSame(A,B) || isSubStructure(A->left,B) || isSubStructure(A->right,B);
        //存在子结构的条件：A、B节点开始存在子结构，或剩下的其中一个节点存在子结构。
    }
};