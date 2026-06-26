class Solution {
public:
    int maxProfit(vector<int>& p) {
        int bestbuy = INT_MAX;
        int bestsell = 0;

        for (int i = 0; i < p.size(); i++){
            bestbuy = min(bestbuy, p[i]);
            bestsell = max(bestsell, p[i] - bestbuy);
        }

        return bestsell;

    }
};
