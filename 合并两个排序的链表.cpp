class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head=new ListNode(0),*cur=head;   
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val<=l2->val){
                cur->next=l1;
                cur=cur->next;
                l1=l1->next;
            }
            else{
                cur->next=l2;
                cur=cur->next;
                l2=l2->next;
            }
        }
        cur->next=l1==nullptr?l2:l1;
        return head->next;
    }
};

class Solution {    //ตÝน้
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr)
            return l2;
        else if(l2==nullptr)
            return l1;
        else if(l1->val<l2->val){
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next=mergeTwoLists(l1,l2->next)
            return l2;
        }
    }
};