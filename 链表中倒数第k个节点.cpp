class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(head==nullptr)
            return nullptr;
        ListNode *first=head,*second=head;
        while(k--)
            first=first->next;  
        while(first!=nullptr){
            first=first->next;
            second=second->next;
        }
        return second;
    }
};