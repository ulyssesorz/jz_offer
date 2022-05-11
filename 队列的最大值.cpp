class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if(!dq.empty())
            return dq.front();
        return -1;
    }
    
    void push_back(int value) {
        q.push(value);
        while(!dq.empty() && dq.back() <= value)    //保持单调性
            dq.pop_back();
        dq.push_back(value);
    }
    
    int pop_front() {
        if(q.empty())
            return -1;
        int top = q.front();
        q.pop();
        if(!dq.empty() && top == dq.front())
            dq.pop_front();
        return top;
    }
private:
    queue<int> q;
    deque<int> dq;
};