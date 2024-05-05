class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> postorder;
        for(int i = 0; i < tokens.size();i++){
            string str = tokens[i];
            if(str.size() > 1 || isdigit(str[0])){
                postorder.push(stoi(str));
                continue;
            }
            int n1 = postorder.top();
            postorder.pop();
            int n2 = postorder.top();
            postorder.pop();
            if(tokens[i] == "+"){            
                postorder.push(n2+n1);
            }
            if(tokens[i] == "/"){
                postorder.push(n2/n1);
            }
            if(tokens[i] == "*"){
                postorder.push(n2*n1);
            }
            if(tokens[i] == "-"){
                postorder.push(n2-n1);
            }
        }
        return postorder.top();
    }
};