class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> A,B;
    MinStack() {

    }
    
    void push(int x) {
        A.push(x);
        if(B.empty()){
            B.push(x);
        }
        else if(x<=B.top()){//等于也要！
            B.push(x);
        }
        return;
    }
    
    void pop() {
        int tmp=A.top();
        A.pop();
        if(!B.empty() && tmp==B.top()){
            B.pop();
        }
        return;
    }
    
    int top() {
        if(!A.empty()){
            return A.top();
        }
        return -1;
    }
    
    int min() {
        if(!B.empty()){
            return B.top();
        }
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
