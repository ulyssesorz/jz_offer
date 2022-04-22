class Solution {
public:
    bool isSame(TreeNode* A, TreeNode* B){
        if(B==nullptr)      //B�Ѿ�Խ��Ҷ�ڵ�
            return true;
        if(A==nullptr)      //B���յ�AΪ��
            return false;
        return (A->val==B->val) && isSame(A->left,B->left) && isSame(A->right,B->right);
        //�ṹ��ͬ����������ǰֵ��ȡ������ӽڵ�Ҳ��ͬ    
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A==nullptr || B==nullptr)    //�ų�����һ��Ϊ�����Ŀ���
            return false;
        return isSame(A,B) || isSubStructure(A->left,B) || isSubStructure(A->right,B);
        //�����ӽṹ��������A��B�ڵ㿪ʼ�����ӽṹ����ʣ�µ�����һ���ڵ�����ӽṹ��
    }
};