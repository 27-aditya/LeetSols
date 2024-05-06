class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = 0;
        for(int i = 0; i < n; i++){
            high = max(piles[i], high);
        }
        int result  = high;
        while(low <= high){
            int mid = low + (high-low)/2;
            long int sum = 0;
            for(int i = 0; i < piles.size(); i++){
                sum += ceil((double)piles[i]/mid);
            }
            if(sum <= h){
                result = min(result, mid);
                high = mid-1;
            }
            else if(sum > h)
                low = mid+1;
        }
        return result;
    }
};