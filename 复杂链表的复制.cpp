class Solution //哈希法
{
public:
    unordered_map<Node*, Node*> cachedNode;

    Node* copyRandomList(Node* head) {
        Node* cur=head;
        while(cur!=nullptr)
        {
            cachedNode[cur]=new Node(cur->val); //建立原链表和新链表每个节点之间的映射关系
            cur=cur->next;
        }
        cur=head;
        while(cur!=nullptr)
        {
            cachedNode[cur]->next=cacheNode[cur->next];
            cachedNode[cur]->radom=cachedNode[cur->random]; //在新链表中还原next和random
            cur=cur->next;
        }
        return cachedNode[head];
    }
};
class Solution //合并拆分法
{
public:
    Node* copyRandomList(Node* head) 
    {
        if(head==nullptr)
            return nullptr;
        Node* cur=head;
        while(cur!=nullptr)
        {
            Node* temp=new Node(cur->val);  //建立新旧链表的间隔拼接
            temp->next=cur->next;
            cur->next=temp;
            cur=cur->next->next;
        }
        cur=head;
        while(cur!=nullptr)
        {
            if(cur->random!=nullptr)
                cur->next->random=cur->random->next;    //还原random指针
            cur=cur->next->next;
        }
        cur=head->next;
        Node* pre=head;
        Node* res=head->next;
        while(cur->next!=nullptr)
        {
            pre->next=pre->next->next;  //拆分两个链表
            cur->next=cur->next->next;
            pre=pre->next;
            cur=cur->next;
        }
        return res;
    }
};