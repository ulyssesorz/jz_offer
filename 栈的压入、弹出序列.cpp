class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.empty() && popped.empty())
            return true;
        if(pushed.empty() || popped.empty())
            return false;
        stack<int> st;
        int i = 0;
        for(int n : pushed){    //栈顶元素和pop[i]相同则出栈，不同则入栈
            st.push(n);
            while(!st.empty() && st.top() == popped[i]){
                st.pop();
                ++i;
            }
        }
        return st.empty();
    }
};

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.empty() && popped.empty())
            return true;
        if(pushed.empty() || popped.empty())
            return false;
        stack<int> st;
        int i = 0, j = 0;
        while(j < popped.size()){ 
            if(st.empty()){
                if(i == pushed.size())
                    return false;
                st.push(pushed[i++]);
            }
            if(st.top() == popped[j]){
                st.pop();
                ++j;
                if(j == popped.size())
                    return true;
            }
            else{
                if(i != pushed.size())
                    st.push(pushed[i++]);
                else
                    return false;
            }
        }
        return false;
    }
};
