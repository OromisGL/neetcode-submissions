class MinStack {
public:

    stack<int> st;
    stack<int> minst;

    MinStack() {
        minst.push(INT_MAX);
    }
    
    void push(int val) {
        st.push(val);
        if (minst.top() >= val)
            minst.push(val);
    }
    
    void pop() {
        if (st.empty()) return;
        int val = st.top();
        st.pop();
        if (!minst.empty() && val == minst.top()) minst.pop();
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        if (minst.empty()) return INT_MAX;
        return minst.top();
    }
};
