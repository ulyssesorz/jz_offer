class Solution  //������
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* p=NULL;
        while(head!=NULL)
        {
            ListNode* temp=head->next;  //β�巨��ת
            head->next=p;
            p=head;
            head=temp;
        }
        return p;
    }
};
// class Solution   //�ݹ�д��
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