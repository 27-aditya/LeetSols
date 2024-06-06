class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>stk;
        for(auto asteroid : asteroids){
            bool destroyed = false;

            while(!stk.empty() && asteroid < 0 && stk.top() > 0){
                if(stk.top() < -asteroid){ 
                    stk.pop();
                    continue;
                }
                else if(stk.top() == -asteroid){
                    destroyed = true;
                    stk.pop();
                    break;
                }
                else{
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed)
                stk.push(asteroid);
        }
        vector<int> res;
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};