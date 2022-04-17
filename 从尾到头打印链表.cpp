class Solution {
private:
    stack<int> st;
public:
    vector<int> reversePrint(ListNode* head) 
    {
        ListNode* p=head;
        while(p!=NULL)
        {
            st.push(p->val);
            p=p->next;
        }
        vector<int> res;
        while(!st.empty())
        {   
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};