class MinStack {
    stack<long long> st;
    long long mini;
public:
    MinStack() {
        while(st.empty()==false) st.pop();
        mini=INT_MAX;
    }
    
    void push(int val) {
        long long value=val;
        if(st.empty()){
            mini=value;
            st.push(value);
        }else{
            if(value<mini){
                st.push(2*value-mini);
                mini=value;
            }else{
                st.push(value);
            }
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long el=st.top();
        st.pop();
        if(el<mini){
            mini=2*mini-el;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        long long el=st.top();
        if(el<mini) return mini;
        return el; 
    }
    
    int getMin() {
        return mini;
    }
};