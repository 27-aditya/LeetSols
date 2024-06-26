class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int price = prices[0];
        for(int i = 1; i < prices.size();i++){
            maxprofit = max(maxprofit, prices[i]-price);
            price = min(price, prices[i]);
        }
        return maxprofit;
    }
};