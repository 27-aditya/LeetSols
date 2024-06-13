class FreqStack {
public:
    priority_queue<pair<int,pair<int,int>>>pq;
    unordered_map<int,int>map;
    int pos = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        pq.push({++map[val],{pos++, val}});
    }
    
    int pop() {
        auto p = pq.top();
        pq.pop();
        int val = p.second.second;
        map[val]--;
        return val;
    }       
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */