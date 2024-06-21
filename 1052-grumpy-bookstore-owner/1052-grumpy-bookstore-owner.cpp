class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int left = 0;
        int right = 0;
        int gsum = 0;
        int maxgsum = 0;
        while(right < grumpy.size()){
            if(grumpy[right] == 1)
                gsum += customers[right];

            if(right-left+1 == minutes){
                maxgsum = max(gsum, maxgsum);
                
                if(grumpy[left] == 1)
                    gsum -= customers[left];
                left++;
            }
            right++;
        }

        int res = 0;
        for(int i = 0; i < grumpy.size(); i++){
            if(grumpy[i] == 0)
                res += customers[i];
        }

        return res+maxgsum;
    }
};