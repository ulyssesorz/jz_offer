class Solution  //迭代法
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* p=NULL;
        while(head!=NULL)
        {
            ListNode* temp=head->next;  //尾插法反转
            head->next=p;
            p=head;
            head=temp;
        }
        return p;
    }
};
// class Solution   //递归写法
// {
// public:
//     ListNode* reverseList(ListNode* head) 
//     {
//         if(!head||!head->next)
//             return head;
//         ListNode* newhead=reverseList(head);
//         head->next->next=head;
//         head->next=nullptr;
//         return head;
//     }
// };