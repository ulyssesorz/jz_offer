class Solution 
{
private:
    stack<int> st;
public:
    vector<int> reversePrint(ListNode* head) 
    {
        ListNode* p=head;
        while(p!=NULL)
        {
            st.push(p->val);    //���ֵ����ѹջ
            p=p->next;
        }
        vector<int> res;
        while(!st.empty())
        {   
            res.push_back(st.top());    //���γ�ջ���������
            st.pop();
        }
        return res;
    }
};