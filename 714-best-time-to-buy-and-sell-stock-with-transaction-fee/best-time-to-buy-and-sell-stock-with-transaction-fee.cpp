class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size(), op1;
        vector<int>ahead(2, 0), curr(2, 0);
        for(int i = n - 1;i>=0;i--){
            for(int buy = 0;buy <= 1;buy++){
                if(buy == 0) op1 = max(prices[i] + ahead[1], ahead[0]);
                if(buy == 1) op1 = max(ahead[0] - prices[i] - fee, ahead[1]);
                curr[buy] = op1;
            }
            ahead = curr;
        }
        return curr[1];
    }
};