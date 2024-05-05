class MinStack {
private:
    vector<int> stak;
    vector<int> minstak;
public:
    MinStack() {
    }
    
    void push(int val) {
        stak.push_back(val);
        if(minstak.empty() || val < minstak.back())
            minstak.push_back(val);
        else
            minstak.push_back(minstak.back());
    }
    
    void pop() {
        if(!stak.empty()){
            stak.erase(stak.end()-1, stak.end());
            minstak.erase(minstak.end()-1, minstak.end());
        }
    }
    
    int top() {
        if(!stak.empty())
            return stak.back();
        return -1;
    }
    
    int getMin() {
        if(!stak.empty())
            return minstak.back();
        return -1;
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