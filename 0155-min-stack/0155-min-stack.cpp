class MinStack {
private:
    vector<int> stak;
    int min = INT_MAX;
public:
    MinStack() {
    }
    
    void push(int val) {
        stak.push_back(val);
    }
    
    void pop() {
        if(!stak.empty())
            stak.erase(stak.end()-1, stak.end());

    }
    
    int top() {
        if(!stak.empty())
            return stak.back();
        return -1;
    }
    
    int getMin() {
        vector<int> ans = stak;
        sort(ans.begin(), ans.end());
        min = ans[0];
        if(!stak.empty())
            return min;
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