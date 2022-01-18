class MyStack {
public:
    queue<int> current,backup;
    MyStack() {

    }
    
    void push(int x) {
        backup.push(x);
        while(!current.empty()){
            backup.push(current.front());
            current.pop();
        }
        swap(current,backup);
    }
    
    int pop() {
        int tmp=current.front();
        current.pop();
        return tmp;
    }
    
    int top() {
        if(current.empty()) return -1;
        return current.front();
    }
    
    bool empty() {
        return current.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
