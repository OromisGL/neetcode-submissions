class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestbuy = INT_MAX;
        int bestsell = 0;

        for (int i = 0; i < prices.size(); i++){
            bestbuy = min(prices[i], bestbuy);
            bestsell = max(bestsell, prices[i] - bestbuy);
        }

        return bestsell;
    }
};
