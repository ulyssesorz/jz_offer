class Solution //��ϣ��
{
public:
    unordered_map<Node*, Node*> cachedNode;

    Node* copyRandomList(Node* head) {
        Node* cur=head;
        while(cur!=nullptr)
        {
            cachedNode[cur]=new Node(cur->val); //����ԭ�����������ÿ���ڵ�֮���ӳ���ϵ
            cur=cur->next;
        }
        cur=head;
        while(cur!=nullptr)
        {
            cachedNode[cur]->next=cacheNode[cur->next];
            cachedNode[cur]->radom=cachedNode[cur->random]; //���������л�ԭnext��random
            cur=cur->next;
        }
        return cachedNode[head];
    }
};
class Solution //�ϲ���ַ�
{
public:
    Node* copyRandomList(Node* head) 
    {
        if(head==nullptr)
            return nullptr;
        Node* cur=head;
        while(cur!=nullptr)
        {
            Node* temp=new Node(cur->val);  //�����¾�����ļ��ƴ��
            temp->next=cur->next;
            cur->next=temp;
            cur=cur->next->next;
        }
        cur=head;
        while(cur!=nullptr)
        {
            if(cur->random!=nullptr)
                cur->next->random=cur->random->next;    //��ԭrandomָ��
            cur=cur->next->next;
        }
        cur=head->next;
        Node* pre=head;
        Node* res=head->next;
        while(cur->next!=nullptr)
        {
            pre->next=pre->next->next;  //�����������
            cur->next=cur->next->next;
            pre=pre->next;
            cur=cur->next;
        }
        return res;
    }
};