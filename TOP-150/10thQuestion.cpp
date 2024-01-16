class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int minPrice = INT_MAX;

        for (int i = 0; i < n; ++i) {
            // Update the minimum price if we find a smaller price
            minPrice = min(minPrice, prices[i]);

            // Update the maximum profit if we find a better selling day
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};