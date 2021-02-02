class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> s;
    
    MinStack() {
    }
    
    void push(int x) {
        
        if(st.empty()){
            st.push(x);
            s.push(x);
        }else{
            
            s.push(min(s.top(),x));
            st.push(x);
            
        }
        
        
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
            s.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return s.top();
    }
    
    
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */