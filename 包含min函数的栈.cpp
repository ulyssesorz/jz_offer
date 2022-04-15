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
        if(x<st_min.top())
            st_min.push(x);
    }
    
    void pop() 
    {
        int temp=st.top();
        st.pop();
        if(temp==st_min.top())
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
