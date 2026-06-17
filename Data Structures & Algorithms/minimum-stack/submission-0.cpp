class MinStack {
public:
    stack<int> m;
    stack<int> s;
    MinStack() {
    }
    
    void push(int val) {
        if(!m.empty())
            m.push(min(m.top(),val));
        else 
            m.push(val);
        s.push(val);
    }
    
    void pop() {
        m.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return m.top();
    }
};
