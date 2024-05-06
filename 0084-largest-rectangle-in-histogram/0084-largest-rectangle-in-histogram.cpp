class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> stack;
        // index, height
        int n = heights.size();
        int result = 0;
        for(int i = 0; i < n; i++){ 
            int start = i;
            while(!stack.empty() && stack.top().second > heights[i]){
                int index = stack.top().first;
                int height = stack.top().second;
                int width = i - index;
                stack.pop();

                result = max(result, height*width);
                start = index;
            }
            stack.push({start, heights[i]});
        }
        while(!stack.empty()){
            int width = n-stack.top().first;
            result = max(result, width*stack.top().second);
            stack.pop();
        }
        return result;
    }
};