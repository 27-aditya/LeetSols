class MyQueue {
private:
    stack<int>stk1;
    stack<int>stk2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stk1.push(x);
        if(stk2.empty()){
            int top = stk1.top();
            stk2.push(top);
            stk1.pop();
        }
    }
    
    int pop() {
        int top = stk2.top();
        stk2.pop(); 
        if(stk2.empty()){
            while(!stk1.empty()){
                int pass = stk1.top();
                stk2.push(pass);
                stk1.pop();
            }
        }
        return top;
    }
    
    int peek() {
        return stk2.top();
    }
    
    bool empty() {
        return stk1.empty() && stk2.empty();
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