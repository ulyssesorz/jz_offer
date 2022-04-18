class MinStack 
{
private:
    stack<int> st;
    stack<int> st_min;
public:
    MinStack()
    {}
    
    void push(int x) 
    {
        st.push(x);
        if(st_min.empty())  
            st_min.push(x);
        else if(x<=st_min.top())    //x��Ҳ������Сֵ����minջ����
            st_min.push(x);
    }
    
    void pop() 
    {
        int temp=st.top();
        st.pop();
        if(!st_min.empty()&&temp==st_min.top()) //st��������Сֵ����st_minҲ����
            st_min.pop();
    }
    
    int top() 
    {
        return st.top();
    }
    
    int min() 
    {
        return st_min.top();
    }
};