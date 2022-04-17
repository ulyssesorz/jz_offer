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
            st.push(p->val);    //结点值依次压栈
            p=p->next;
        }
        vector<int> res;
        while(!st.empty())
        {   
            res.push_back(st.top());    //依次出栈到结果数组
            st.pop();
        }
        return res;
    }
};