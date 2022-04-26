class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head==nullptr)
            return nullptr;     //������
        if(head->val==val)
            return head->next;  //��ͷ�ڵ�
        ListNode *pre=head,*cur=head->next;
        while(cur!=nullptr && cur->val!=val){
            pre=pre->next;
            cur=cur->next;  //��val��λ��
        }
        if(cur!=nullptr)
            pre->next=cur->next;
        return head;
    }   
};

class Solution {    //�ݹ�
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head==nullptr)
            return nullptr;
        if(head->val==val)
            return head->next;
        head->next=deleteNode(head->next,val);
        return head;
    }   
};