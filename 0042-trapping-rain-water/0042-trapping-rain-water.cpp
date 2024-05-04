class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        vector<int> maxleft(height.size(),0);
        vector<int> maxright(height.size(), 0);
        maxleft[0] = height[0];
        for(int i = 1; i < height.size(); i++)
            maxleft[i] = max(maxleft[i-1], height[i]);
        maxright[height.size()-1] = height[height.size()-1];
        for(int i = height.size()-2; i >=0; i-- )
            maxright[i] = max(maxright[i+1], height[i]);
        for(int i = 1; i < height.size()-1; i++){
            water += max(min(maxleft[i], maxright[i])-height[i], 0);
        }
        return water;
    }
};