class MaxQueue {
public:
    queue<int> realq;
    deque<int> virtualq;//单调递减队列，你每次都弄混！！！
    MaxQueue() {

    }
    
    int max_value() {
        if(!virtualq.empty()){
            return virtualq.front();
        }
        else return -1;
    }
    
    void push_back(int value) {
        realq.push(value);
        while(!virtualq.empty() && virtualq.back()<value){
            virtualq.pop_back();
        }
        virtualq.push_back(value);
    }
    
    int pop_front() {
        if(realq.empty()) return -1;
        int temp=realq.front();
        realq.pop();
        if(!virtualq.empty() && virtualq.front()==temp){
            virtualq.pop_front();
        }
        return temp;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
