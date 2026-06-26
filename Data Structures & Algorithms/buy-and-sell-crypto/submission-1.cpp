class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        int bestbuy = INT_MAX;
        int bestsell = 0;

        for (int p : prices){
            bestbuy = min(bestbuy, p);
            bestsell = max(bestsell, p - bestbuy);
        }
        return bestsell;
    }
};
