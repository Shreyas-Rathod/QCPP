class MinStack {
public:
    stack<long long>s;
    long long mini;
    MinStack() {}
    
    void push(int val) {
        if(s.empty()){
            mini = val;
            s.push(val);
        }else{
            if(mini < val) s.push(val);
            else {
                s.push(2*(long long)val-mini);
                mini = val;
            }
        }
    }
    
    void pop() {
        if(s.empty()) return;
        long long x = s.top();
        s.pop();
        if(x < mini) mini = 2*(long long)mini - x; 
    }
    
    int top() {
        if(s.empty()) return -1;
        if(s.top() < mini) return mini;
        return s.top();
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */