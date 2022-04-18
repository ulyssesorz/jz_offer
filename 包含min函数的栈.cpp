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
        else if(x<=st_min.top())    //x（也）是最小值，入min栈保存
            st_min.push(x);
    }
    
    void pop() 
    {
        int temp=st.top();
        st.pop();
        if(!st_min.empty()&&temp==st_min.top()) //st出的是最小值，则st_min也弹出
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