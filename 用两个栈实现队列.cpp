class CQueue 
{
public:
    stack<int> stack_1,stack_2;
    CQueue() 
    {}
    
    void appendTail(int value) 
    {
        stack_1.push(value);
    }
    
    int deleteHead() 
    {
        if(stack_2.empty()) 
        {
            if(stack_1.empty())
                return -1;
            while(!stack_1.empty())
            {
                int temp=stack_1.top(); //stack_1元素全部移动到stack_2
                stack_1.pop();
                stack_2.push(temp);
            }
        }
        int num=stack_2.top();  //stack_2非空时直接输出
        stack_2.pop();
        return num;
    }
};