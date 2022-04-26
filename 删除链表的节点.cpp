class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head==nullptr)
            return nullptr;     //空链表
        if(head->val==val)
            return head->next;  //在头节点
        ListNode *pre=head,*cur=head->next;
        while(cur!=nullptr && cur->val!=val){
            pre=pre->next;
            cur=cur->next;  //找val的位置
        }
        if(cur!=nullptr)
            pre->next=cur->next;
        return head;
    }   
};

class Solution {    //递归
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