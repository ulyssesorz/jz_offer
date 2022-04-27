class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA=headA,*curB=headB;
        while(curA!=curB){
            curA=curA==nullptr?headB:curA->next;
            curB=curB==nullptr?headA:curB->next;
        }
        return curA;
    }
};

class Solution {
public:
    int getLength(ListNode* list){  //获取链表长度
        int len=0;
        while(list!=nullptr){
            ++len;
            list=list->next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=getLength(headA),lenB=getLength(headB);
        if(lenA>lenB){
            int n=lenA-lenB;
            while(n--)
                headA=headA->next;
        }
        if(lenA<lenB){
            int n=lenB-lenA;
            while(n--)
                headB=headB->next;
        }
        while(headA!=nullptr && headB!=nullptr){
            if(headA==headB)
                return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};