class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size() ;

        int minPrice = prices[0], profit=0 ;
        for(int i=0 ; i<n ; i++){
            profit = max(profit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }

        return profit ;
    }
};