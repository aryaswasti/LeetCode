class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        //store reverse list in s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        
        //add new element to end of stack
        s1.push(x);
        
        //add reversed list back to s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        //since newest elemt is in bottom of stack
        //first element is on top of stack
        int temp = s1.top();
        s1.pop();
        return temp;
    }
    
    int peek() {
        //first element is on top of stack
        return s1.top();
    }
    
    bool empty() {
        //s1 contains orignal queue elements
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */